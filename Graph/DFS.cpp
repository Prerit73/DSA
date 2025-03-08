#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> adj, int u, vector<bool> &visited, vector<int> &ans)
{
    if (visited[u])
    {
        return;
    }

    visited[u] = true;
    ans.push_back(u);

    for (int v = 0; v < adj[u].size(); v++)
    {
        if (!visited[adj[u][v]])
        {
            dfs(adj, adj[u][v], visited, ans);
        }
    }
}

vector<int> dfsOfGraph(int v, vector<vector<int>> adj)
{
    vector<int> ans;
    vector<bool> visited(v, false);

    dfs(adj, 0, visited, ans);

    return ans;
}

vector<int> dfsUsingStack(int v, vector<vector<int>> adj)
{
    vector<int> ans;
    vector<bool> visited(v, false);
    stack<int> s;

    s.push(0);
    visited[0] = true;

    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        ans.push_back(u);

        for (int v = 0; v < adj[u].size(); v++)
        {
            if (!visited[adj[u][v]])
            {
                s.push(adj[u][v]);
                visited[adj[u][v]] = true;
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
    vector<int> ans = dfsOfGraph(v, adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}