#include <iostream>
using namespace std;

#define MAX 100



struct Node
{
    int info;
};
typedef struct Node NODE;

int Hash(int x)
{
    return x % MAX;
}

void CreateHashTable(NODE *HT[])
{
    for (int i = 0; i < MAX; i++)
        HT[i] = NULL;
}

NODE *CreateNode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    return p;
}

void InsertNode(NODE *HT[], int x)
{
    int index = Hash(x);
    NODE *p = CreateNode(x);
    while (HT[index] != NULL)
    {
        index = Hash(index + 1);
    }
    HT[index] = p;
}

NODE *SearchNode(NODE *HT[], int x)
{
    int index = Hash(x);
    while (HT[index]->info != x && HT[index]->info != NULL)
    {
        index = Hash(index + 1);
    }
    if (HT[index] != NULL)
        return HT[index];
    return NULL;
}

void DeleteNode(NODE *HT[], int x)
{
    int index = Hash(x);
    while (HT[index]->info != x && HT[index]->info != NULL)
    {
        index = Hash(index + 1);
    }
    if (HT[index]->info == x)
        HT[index] = NULL;
}

void PrintHashTable(NODE *HT[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (HT[i] != NULL)
            cout << i << ": " << HT[i]->info << endl;
        else
            cout << i << ": NULL" << endl;
    }
    cout << endl;
}

int main()
{
    NODE *HT[MAX];
    CreateHashTable(HT);
    InsertNode(HT, 1);
    InsertNode(HT, 2);
    InsertNode(HT, 3);
    InsertNode(HT, 4);
    InsertNode(HT, 5);
    InsertNode(HT, 6);
    InsertNode(HT, 7);
    InsertNode(HT, 8);
    InsertNode(HT, 9);
    InsertNode(HT, 10);
    PrintHashTable(HT);
    NODE *p = SearchNode(HT, 1);
    if (p != NULL)
        cout << "Found: " << p->info << endl;
    else
        cout << "Not Found! " << endl;
    DeleteNode(HT, 1);
    PrintHashTable(HT);
    return 0;
}