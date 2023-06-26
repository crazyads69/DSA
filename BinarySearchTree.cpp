#include <iostream>
using namespace std;

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};
typedef struct Node *Tree;

void CreateTree(Tree &root)
{
    root = NULL;
}

Node *CreateNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void AddNode(Tree &root, Node *p)
{
    if (root != NULL)
    {
        if (root->info == p->info)
            return;
        else if (root->info > p->info)
            AddNode(root->left, p);
        else
            AddNode(root->right, p);
    }
    else
        root = p;
}

void NLR(Tree root)
{
    if (root != NULL)
    {
        cout << root->info << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(Tree root)
{
    if (root != NULL)
    {
        LNR(root->left);
        cout << root->info << " ";
        LNR(root->right);
    }
}

void LRN(Tree root)
{
    if (root != NULL)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root->info << " ";
    }
}

void DestroyTree(Tree &root)
{
    if (root != NULL)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}

Node *SearchNode(Tree root, int x)
{
    if (root != NULL)
    {
        if (root->info == x)
            return root;
        else if (root->info > x)
            return SearchNode(root->left, x);
        else
            return SearchNode(root->right, x);
    }
    return NULL;
}

int CountNode(Tree root)
{
    if (root == NULL)
        return 0;
    return 1 + CountNode(root->left) + CountNode(root->right);
}

int CountLeaf(Tree root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return CountLeaf(root->left) + CountLeaf(root->right);
}

int SumNodeAtSameLevel(Tree root, int k, int level = 0)
{
    if (root == NULL)
        return 0;
    if (level == k)
        return root->info;
    return SumNodeAtSameLevel(root->left, k, level + 1) + SumNodeAtSameLevel(root->right, k, level + 1);
}

int CountNodeHasOneChild(Tree root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right != NULL)
        return 1 + CountNodeHasOneChild(root->right);
    if (root->left != NULL && root->right == NULL)
        return 1 + CountNodeHasOneChild(root->left);
    return CountNodeHasOneChild(root->left) + CountNodeHasOneChild(root->right);
}

int CountNodeHasTwoChild(Tree root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL && root->right != NULL)
        return 1 + CountNodeHasTwoChild(root->left) + CountNodeHasTwoChild(root->right);
    return CountNodeHasTwoChild(root->left) + CountNodeHasTwoChild(root->right);
}

int HeightBST(Tree root)
{
    if (root == NULL)
        return 0;
    int left = HeightBST(root->left);
    int right = HeightBST(root->right);
    if (left > right)
        return left + 1;
    return right + 1;
}

void FindAndReplaceMaxLeft(Tree &p, Tree &root)
{
    if (root->right != NULL)
        FindAndReplaceMaxLeft(p, root->right);
    else
    {
        p->info = root->info;
        p = root;
        root = root->left;
    }
}

void FindAndReplaceMinRight(Tree &p, Tree &root)
{
    if (root->left != NULL)
        FindAndReplaceMinRight(p, root->left);
    else
    {
        p->info = root->info;
        p = root;
        root = root->right;
    }
}

void DeleteNode(Tree &root, int x)
{
    if (root != NULL)
    {
        if (root->info > x)
            DeleteNode(root->left, x);
        else if (root->info < x)
            DeleteNode(root->right, x);
        else
        {
            Node *p = root;
            if (root->left == NULL)
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            else
                FindAndReplaceMaxLeft(p, root->left); // Cach 1
            // FindAndReplaceMinRight(p, root->right); // Cach 2
            delete p;
        }
    }
}

int main()
{
    Tree root;
    CreateTree(root);
    AddNode(root, CreateNode(5));
    AddNode(root, CreateNode(3));
    AddNode(root, CreateNode(7));
    AddNode(root, CreateNode(2));
    AddNode(root, CreateNode(4));
    AddNode(root, CreateNode(6));
    AddNode(root, CreateNode(8));
    AddNode(root, CreateNode(1));
    AddNode(root, CreateNode(9));
    AddNode(root, CreateNode(10));
    AddNode(root, CreateNode(11));
    AddNode(root, CreateNode(12));
    AddNode(root, CreateNode(13));
    AddNode(root, CreateNode(14));
    AddNode(root, CreateNode(15));
    AddNode(root, CreateNode(16));
    AddNode(root, CreateNode(17));
    AddNode(root, CreateNode(18));
    AddNode(root, CreateNode(19));
    AddNode(root, CreateNode(20));
    AddNode(root, CreateNode(21));
    AddNode(root, CreateNode(22));
    NLR(root);
    cout << endl;
    LNR(root);
    cout << endl;
    LRN(root);
    cout << endl;
    cout << "So nut: " << CountNode(root) << endl;
    cout << "So nut la: " << CountLeaf(root) << endl;
    cout << "So nut co 1 con: " << CountNodeHasOneChild(root) << endl;
    cout << "So nut co 2 con: " << CountNodeHasTwoChild(root) << endl;
    cout << "Chieu cao cua cay: " << HeightBST(root) << endl;
    DeleteNode(root, 5);
    NLR(root);
    cout << endl;
    LNR(root);
    cout << endl;
    LRN(root);
    cout << endl;
    cout << "So nut: " << CountNode(root) << endl;
    cout << "So nut la: " << CountLeaf(root) << endl;
    cout << "So nut co 1 con: " << CountNodeHasOneChild(root) << endl;
    cout << "So nut co 2 con: " << CountNodeHasTwoChild(root) << endl;
    cout << "Chieu cao cua cay: " << HeightBST(root) << endl;
    DestroyTree(root);
    return 0;
}