#include <bits/stdc++.h>
using namespace std;

bool isDfsCycle(vector<vector<int>> adj, int u, vector<bool> &visited, int parent)
{
    visited[u] = true;

    for (int v : adj[u])
    {
        if (parent == v)
        {
            continue; // skip the parent node
        }
        if (visited[v])
        {
            return true;
        }

        if (isDfsCycle(adj, v, visited, u))
        {
            return true;
        }
    }

    return false;
}

bool isCycle(int v, vector<vector<int>> adj)
{
    vector<bool> visited(v, false);

    for (int u = 0; u < adj.size(); u++)
    {
        if (!visited[u] && isDfsCycle(adj, u, visited, -1))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // O(V+E)
    int v = 5;
    vector<vector<int>> adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    bool isCycleDetect = isCycle(v, adj);

    cout <<"is cycle "<< isCycleDetect;

    return 0;
}