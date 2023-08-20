#include <bits/stdc++.h>
using namespace std;

vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
{
    int maxGroup = 0;
    for (auto i : group)
    {
        maxGroup = max(maxGroup, i);
    }
    for (int i = 0; i < n; i++)
    {
        if (group[i] == -1)
            group[i] = ++maxGroup;
    }

    vector<vector<int>> itemAdjList(n);
    vector<unordered_set<int>> groupAdjList(maxGroup + 1);
    for (int i = 0; i < n; i++)
    {
        if (beforeItems[i].size())
        {
            for (int item : beforeItems[i])
            {
                itemAdjList[item].push_back(i);
                if (group[item] != group[i])
                    groupAdjList[group[item]].insert(group[i]);
            }
        }
    }

    vector<int> itemIndegree(n, 0);
    vector<int> groupIndegree(maxGroup + 1, 0);
    for (vector<int> nodes : itemAdjList)
    {
        for (int node : nodes)
        {
            itemIndegree[node]++;
        }
    }

    for (unordered_set<int> groups : groupAdjList)
    {
        for (int group : groups)
        {
            groupIndegree[group]++;
        }
    }

    vector<int> itemTopologicalSort;
    vector<int> groupTopologicalSort;

    stack<int> st;
    for (int i = 0; i < n; i++)
        if (itemIndegree[i] == 0)
            st.push(i);
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        itemTopologicalSort.push_back(curr);
        for (int node : itemAdjList[curr])
        {
            if (--itemIndegree[node] == 0)
                st.push(node);
        }
    }

    if (itemTopologicalSort.size() != n)
        return {};

    for (int i = 0; i <= maxGroup; i++)
        if (groupIndegree[i] == 0)
            st.push(i);
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        groupTopologicalSort.push_back(curr);
        for (int node : groupAdjList[curr])
        {
            if (--groupIndegree[node] == 0)
                st.push(node);
        }
    }

    if (groupTopologicalSort.size() != maxGroup + 1)
        return {};

    vector<vector<int>> groupItemMap(maxGroup + 1);
    for (int i : itemTopologicalSort)
    {
        groupItemMap[group[i]].push_back(i);
    }

    vector<int> res;
    for (int i : groupTopologicalSort)
    {
        for (int j : groupItemMap[i])
        {
            res.push_back(j);
        }
    }

    return res;
}