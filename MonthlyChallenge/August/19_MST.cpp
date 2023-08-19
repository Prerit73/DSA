#include <bits/stdc++.h>
using namespace std;
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
int findParent(vector<int> &parent, int u)
{
    if (parent[u] == u)
        return u;

    return parent[u] = findParent(parent, parent[u]);
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[v] > rank[u])
    {
        parent[u] = v;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }

    return;
}
int getMst(int n, vector<vector<int>> &e, int exc, int inc)
{
    vector<int> rank(n, 0);
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    int wt = 0;

    if (inc != -1)
    {
        wt += e[inc][2];
        unionSet(findParent(parent, e[inc][0]), findParent(parent, e[inc][1]), parent, rank);
    }

    for (int i = 0; i < e.size(); i++)
    {
        if (i == exc)
            continue;

        int u = findParent(parent, e[i][0]);
        int v = findParent(parent, e[i][1]);

        if (u != v)
        {
            wt += e[i][2];
            unionSet(u, v, parent, rank);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (findParent(parent, i) != findParent(parent, 0))
            return INT_MAX;
    }
    return wt;
}
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        edges[i].push_back(i);
    }

    sort(edges.begin(), edges.end(), cmp);
    vector<int> criti;
    vector<int> pseudo;
    int ori_Mst = getMst(n, edges, -1, -1);

    for (int i = 0; i < edges.size(); i++)
    {

        if (ori_Mst < getMst(n, edges, i, -1))
        {
            criti.push_back(edges[i][3]);
        }
        else if (ori_Mst == getMst(n, edges, -1, i))
        {
            pseudo.push_back(edges[i][3]);
        }
    }

    vector<vector<int>> ans;
    ans.push_back(criti);
    ans.push_back(pseudo);

    return ans;
}
int main()
{
}
