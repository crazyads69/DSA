#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using ll = long long;
const int INF = 1e9;
const int MAX = 1001;

void Input(vector<pair<int, int>> adj[], int m)
{
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // Do thi vo huong
    }
}

void Dijstra(vector<pair<int, int>> adj[], int n, int s)
{
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; // Min heap {Khoang cach, dinh}
    Q.push(make_pair(0, s));                                                           // Khoang cach tu s den s la 0
    // Duyet cac dinh
    while (Q.empty() == false)
    {
        // Chon khoang cach tu s den cac dinh la nho nhat
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second; // Dinh
        int du = top.first; // Khoang cach tu s den u
        if (du > d[u])
            continue;
        // Relaxation: Cap nhat khoang cach tu s den cac dinh ke cua u
        for (int i = 0; i < adj[u].size(); i++)
        {
            pair<int, int> neighbor = adj[u][i];
            int v = neighbor.first;  // Dinh ke cua u
            int w = neighbor.second; // Khoang cach tu u den v
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push(make_pair(d[v], v));
            }
        }
    }
    // In ra khoang cach tu s den cac dinh
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
}

void DijstraPath(vector<pair<int, int>> adj[], int n, int s, int d, int parent[])
{
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    parent[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; // Min heap {Khoang cach, dinh}
    Q.push(make_pair(0, s));                                                           // Khoang cach tu s den s la 0
    // Duyet cac dinh
    while (Q.empty() == false)
    {
        // Chon khoang cach tu s den cac dinh la nho nhat
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second; // Dinh
        int du = top.first; // Khoang cach tu s den u
        if (du > d[u])
            continue;
        // Relaxation: Cap nhat khoang cach tu s den cac dinh ke cua u
        for (int i = 0; i < adj[u].size(); i++)
        {
            pair<int, int> neighbor = adj[u][i];
            int v = neighbor.first;  // Dinh ke cua u
            int w = neighbor.second; // Khoang cach tu u den v
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push(make_pair(d[v], v));
                parent[v] = u;
            }
        }
    }
}

void FindPath(vector < pair<int, int> adj[], int n, int s, int d, int parent[])
{
    DijstraPath(adj, n, s, d, parent);
    vector<int> path;
    int u = d;
    if (parent[u] == -1)
    {
        cout << "No path";
        return;
    }
    else
    {
        while (u != s)
        {
            path.push_back(u);
            u = parent[u];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
    }
}
int main()
{
    vector<pair<int, int>> adj[MAX]; // Adjacency list
    int parent[MAX];
    memset(parent, -1, sizeof(parent));
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    Input(adj, m);
    Dijstra(adj, n, s);
    FindPath(adj, n, s, d, parent);
    return 0;
}
