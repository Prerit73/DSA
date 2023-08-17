#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int row = mat.size(), col = mat[0].size();

    vector<vector<int>> ans(row, vector<int>(col, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;

        for (int k = 0; k < 4; k++)
        {
            int nrow = i + dx[k];
            int ncol = j + dy[k];
            if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && ans[nrow][ncol] == -1)
            {
                ans[nrow][ncol] = ans[i][j] + 1;
                q.push({nrow, ncol});
            }
        }
    }
    return ans;
}
