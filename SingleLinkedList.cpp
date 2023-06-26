#include <iostream>
using namespace std;

struct Node
{
    int info;
    struct Node *pNext;
};
typedef struct Node NODE;

struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

void CreateEmptyList(LIST &l)
{
    l.pHead = l.pTail = NULL;
}

int IsEmptyList(LIST l)
{
    if (l.pHead == NULL)
        return 1;
    return 0;
}

NODE *CreateNode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void AddHead(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void InsertAfterQ(LIST &l, NODE *p, NODE *q)
{
    if (q != NULL)
    {
        p->pNext = q->pNext;
        q->pNext = p;
        if (l.pTail == q)
            l.pTail = p;
    }
    else
        AddHead(l, p);
}

void InputList(LIST &l)
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    CreateEmptyList(l);
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the element " << i + 1 << ": ";
        cin >> x;
        NODE *p = CreateNode(x);
        AddTail(l, p);
    }
}

void SelectionSort(LIST &l)
{
    NODE *p = l.pHead;
    NODE *q = new NODE;
    NODE *min = new NODE;
    while (p != l.pTail)
    {
        min = p;
        q = p->pNext;
        while (q != NULL)
        {
            if (q->info < min->info) // Neu giam dan thi doi thanh (q->info > min->info)
                min = q;
            q = q->pNext;
        }
        // Hoan doi p->info and min->info
        int temp = p->info;
        p->info = min->info;
        min->info = temp;
        p = p->pNext;
    }
}

void QuickSort(LIST &l)
{
    NODE *p = new NODE;
    NODE *X = new NODE;
    LIST l1, l2;
    if (l.pHead == l.pTail)
        return; // Da co thu tu
    CreateEmptyList(l1);
    CreateEmptyList(l2);
    X = l.pHead;
    l.pHead = X->pNext;
    while (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = p->pNext;
        p->pNext = NULL;
        if (p->info <= X->info) // Neu giam dan thi doi thanh (p->info >= X->info)
            AddHead(l1, p);
        else
            AddHead(l2, p);
    }
    QuickSort(l1);
    QuickSort(l2);
    // Noi l1, X, l2 lai voi nhau
    if (l1.pHead != NULL)
    {
        l.pHead = l1.pHead;
        l1.pTail->pNext = X; // Noi X vao cuoi l1
    }
    else
        l.pHead = X;
    X->pNext = l2.pHead;
    if (l2.pHead != NULL) // l2 co 1 phan tu
        l.pTail = l2.pTail;
    else // l2 rong
        l.pTail = X;
}

void PrintList(LIST l)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void RemoveHead(LIST &l)
{
    if (l.pHead != NULL)
    {
        NODE *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
}

void RemoveTail(LIST &l)
{
    if (l.pHead != NULL)
    {
        NODE *p = l.pHead;
        while (p->pNext != l.pTail)
            p = p->pNext;
        delete l.pTail;
        l.pTail = p;
        l.pTail->pNext = NULL;
        if (l.pTail == NULL)
            l.pHead = NULL;
    }
}

void RemoveAfterQ(LIST &l, NODE *q)
{
    if (q != NULL)
    {
        NODE *p = q->pNext;
        if (p != NULL)
        {
            if (p == l.pTail)
                l.pTail = q;
            q->pNext = p->pNext;
            delete p;
        }
    }
    else
        RemoveHead(l);
}

void RemoveX(LIST &l, int x)
{
    NODE *p = l.pHead;
    NODE *q = NULL;
    while (p != NULL)
    {
        if (p->info == x)
            break;
        q = p;
        p = p->pNext;
    }
    if (p != NULL)
        RemoveAfterQ(l, q);
}

NODE *Search(LIST l, int x)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (p->info == x)
            return p;
        p = p->pNext;
    }
    return NULL;
}

void Reverse(LIST &l)
{
    NODE *prev = NULL;
    NODE *current = l.pHead;
    NODE *next = NULL;
    while (current != NULL)
    {
        next = current->pNext;
        current->pNext = prev;
        prev = current;
        current = next;
    }
    l.pHead = prev;
}

void DestroyList(LIST &l)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        RemoveHead(l);
        p = l.pHead;
    }
    l.pTail = NULL;
}

int main()
{
    LIST l;
    InputList(l);
    PrintList(l);
    cout << endl;
    Reverse(l);
    PrintList(l);
    cout << endl;
    QuickSort(l);
    PrintList(l);
    DestroyList(l);
    return 0;
}