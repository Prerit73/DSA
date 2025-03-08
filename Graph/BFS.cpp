#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<vector<int>> adj)
{
    vector<int> ans;
    vector<bool> visited(v, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                q.push(adj[node][i]);
                visited[adj[node][i]] = true;
            }
        }
    }

    return ans;
}

int main()
{
    // O(V+E)
    int v = 5;
    vector<vector<int>> adj = {{2, 3, 1}, {1, 0}, {0, 4}, {0}, {2}};
    vector<int> ans = bfsOfGraph(v, adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}