#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void InputFromMatrix(int a[][1001], vector<int> adj[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
}

void InputFromEdgeList(vector<int> adj[], int m)
{
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Do thi vo huong
    }
}

void PrintAdjList(vector<int> adj[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

void DFS(int u, vector<int> adj[], bool visited[])
{
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (visited[v] == false)
            DFS(v, adj, visited);
    }
}

void BFS(int u, vector<int> adj[], bool visited[])
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (q.empty() == false)
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int i = 0; i < adj[v].size(); i++)
        {
            int x = adj[v][i];
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main()
{
    vector<int> adj[1001];
    int a[1001][1001];
    bool visited[1001];
    memset(visited, false, sizeof(visited));
    int u;
    int n, m;
    cin >> n >> m;
    InputFromEdgeList(adj, m);
    // InputFromMatrix(a, adj, n);
    // PrintAdjList(adj, n);
    cin >> u;
    // BFS(u, adj, visited);
    // DFS(u, adj, visited);
    return 0;
}