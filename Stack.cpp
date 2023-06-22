#include <iostream>
using namespace std;

struct Node
{
    int info;
    struct Node *pNext;
};
typedef struct Node NODE;

struct Stack
{
    NODE *pHead;
};
typedef struct Stack STACK;

void CreateStack(STACK &s)
{
    s.pHead = NULL;
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

int IsEmpty(STACK s)
{
    if (s.pHead == NULL)
        return 1;
    return 0;
}

void Push(STACK &s, NODE *p)
{
    if (IsEmpty(s) == true)
        s.pHead = p;
    else
    {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

int Pop(STACK &s)
{
    if (IsEmpty(s) == true)
        return 0;
    NODE *p = s.pHead;
    int x = p->info;
    s.pHead = s.pHead->pNext;
    delete p;
    return x;
}

int Top(STACK s)
{
    if (IsEmpty(s) == true)
        return 0;
    return s.pHead->info;
}

void PrintStack(STACK s)
{
    while (IsEmpty(s) == false)
    {
        int x;
        cout << Pop(s) << " ";
    }
}

int main()
{
    STACK s;
    CreateStack(s);
    NODE *p = CreateNode(1);
    Push(s, p);
    p = CreateNode(2);
    Push(s, p);
    p = CreateNode(3);
    Push(s, p);
    p = CreateNode(4);
    Push(s, p);
    p = CreateNode(5);
    Push(s, p);
    PrintStack(s);
    return 0;
}