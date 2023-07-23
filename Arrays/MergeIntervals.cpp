#include <bits/stdc++.h>
using namespace std;

bool sortrow(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), sortrow);

    for (int i = 0; i < intervals.size(); i++)
    {
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            // if the current interval lies in the last interval i.e({8,17},{15,18} at the end of the array)
            ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 17}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: "
         << "\n";
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}