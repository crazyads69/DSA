#include <iostream>
using namespace std;

struct Node
{
    int info;
    struct Node *pNext;
};
typedef struct Node NODE;

struct Queue
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct Queue QUEUE;

void CreateQueue(QUEUE &q)
{
    q.pHead = q.pTail = NULL;
}

int IsEmptyQueue(QUEUE q)
{
    if (q.pHead == NULL)
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

void EnQueue(QUEUE &q, NODE *p)
{
    if (IsEmptyQueue(q) == true)
        q.pHead = q.pTail = p;
    else
    {
        q.pTail->pNext = p;
        q.pTail = p;
    }
}

int DeQueue(QUEUE &q)
{
    if (IsEmptyQueue(q) == true)
        return 0;
    NODE *p = q.pHead;
    int x = p->info;
    q.pHead = q.pHead->pNext;
    delete p;
    return x;
}

int Front(QUEUE q)
{
    if (IsEmptyQueue(q) == true)
        return 0;
    return q.pHead->info;
}

void PrintQueue(QUEUE q)
{
    while (IsEmptyQueue(q) == false)
    {
        cout << DeQueue(q) << " ";
    }
}

int main()
{
    QUEUE q;
    CreateQueue(q);
    NODE *p = CreateNode(1);
    EnQueue(q, p);
    p = CreateNode(2);
    EnQueue(q, p);
    p = CreateNode(3);
    EnQueue(q, p);
    p = CreateNode(4);
    EnQueue(q, p);
    p = CreateNode(5);
    EnQueue(q, p);
    PrintQueue(q);
    return 0;
}