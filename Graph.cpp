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

void InputFromAdjList(vector<int> adj[], int n)
{
    int u, v;
    for (int i = 1; i <= n; i++)
    {
        cin >> u;
        while (cin >> v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u); // Do thi vo huong
        }
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

void DFSPath(int u, vector<int> adj[], bool visited[], int parent[])
{
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (visited[v] == false)
        {
            parent[v] = u;
            DFS_Path(v, adj, visited, parent);
        }
    }
}

void FindPath(int u, int v, vector<int> adj[], bool visited[], int parent[])
{
    DFSPath(u, adj, visited, parent);
    // BFSPath(u, adj, visited, parent);
    if (parent[v] == -1)
        cout << "Khong co duong di";
    else
    {
        vector<int> path;
        while (v != u)
        {
            path.push_back(v);
            v = parent[v];
        }
        path.push_back(u);
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
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

void BFSPath(int u, vector<int> adj[], bool visited[], int parent[])
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (q.empty() == false)
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < adj[v].size(); i++)
        {
            int x = adj[v][i];
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
    }
}

int CountConnectedComponents(vector<int> adj[], int n, bool visited[])
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            ++count;
            // cout << "Cac dinh lien thong la " << count << ": ";
            BFS(i, adj, visited); // DFS(i, adj, visited);
            cout << endl;
        }
    }
    return count;
}

bool IsConnected(vector<int> adj[], int n, bool visited[])
{
    int count = CountConnectedComponents(adj, n, visited);
    if (count == 1)
        return true;
    return false;
}

int main()
{
    vector<int> adj[1001];
    int a[1001][1001];
    bool visited[1001];
    int parent[1001];
    memset(parent, -1, sizeof(parent));
    memset(visited, false, sizeof(visited));
    int u;
    int n, m;
    cin >> n >> m;
    InputFromEdgeList(adj, m);
    // InputFromMatrix(a, adj, n);
    // InputFromAdjList(adj, n);
    // PrintAdjList(adj, n);
    cin >> u;
    // BFS(u, adj, visited);
    // DFS(u, adj, visited);
    // FindPath(u, v, adj, visited, parent);
    // cout << CountConnectedComponents(adj, n, visited);
    // cout << IsConnected(adj, n, visited);
    return 0;
}