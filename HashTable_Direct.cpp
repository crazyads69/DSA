#include <iostream>
using namespace std;

#define MAX 100

struct Node
{
    int info;
    struct Node *pNext;
};

typedef struct Node *HashTable[MAX];

void CreateHashTable(HashTable &HT)
{
    for (int i = 0; i < MAX; i++)
        HT[i] = NULL;
}

int Hash(int x)
{
    return x % MAX;
}

Node *CreateNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(Node *&l, int k)
{
    Node *p = CreateNode(k);
    if (l == NULL)
    {
        l = p;
    }
    else
    {
        Node *q = l;
        while (q->pNext != NULL)
            q = q->pNext;
        q->pNext = p;
    }
}

void InsertNode(HashTable &HT, int x)
{
    int index = Hash(x);
    AddTail(HT[index], x);
}

Node *SearchNode(HashTable HT, int x)
{
    int index = Hash(x);
    Node *p = HT[index];
    while (p != NULL)
    {
        if (p->info == x)
            return p;
        p = p->pNext;
    }
    return NULL;
}

void DeleteHead(Node *&l)
{
    if (l == NULL)
        return;
    Node *p = l;
    l = l->pNext;
    delete p;
}

void DeleteAfter(Node *&q)
{
    Node *p = q->pNext;
    if (p == NULL)
        return;
    q->pNext = p->pNext;
    delete p;
}

void DeleteNode(HashTable &HT, int x)
{
    int index = Hash(x);
    Node *p = HT[index];
    Node *q = p;
    while (p != NULL && p->info != x)
    {
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return;
    if (p == HT[index])
        DeleteHead(HT[index]);
    else
        DeleteAfter(q);
}

void PrintHashTable(HashTable HT)
{
    for (int i = 0; i < MAX; i++)
    {
        Node *p = HT[i];
        cout << "HT[" << i << "]: ";
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->pNext;
        }
        cout << endl;
    }
}

int main()
{
    HashTable HT;
    CreateHashTable(HT);
    InsertNode(HT, 1);
    InsertNode(HT, 2);
    InsertNode(HT, 3);
    InsertNode(HT, 4);
    InsertNode(HT, 5);
    InsertNode(HT, 6);
    InsertNode(HT, 7);
    PrintHashTable(HT);
    DeleteNode(HT, 1);
    DeleteNode(HT, 2);
    DeleteNode(HT, 3);
    PrintHashTable(HT);
    return 0;
}