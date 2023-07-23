// link https://leetcode.com/problems/rotate-image/submissions/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate1(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> rotatedMatrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotatedMatrix[j][n - i - 1] = matrix[i][j];
        }
    }

    return rotatedMatrix;
}

vector<vector<int>> rotate2(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}

int main()
{
    vector<vector<int>> arr;
    arr = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    vector<vector<int>> rotated = rotate1(arr); // O(N*N)
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++)
    {
        for (int j = 0; j < rotated[0].size(); j++)
        {
            cout << rotated[i][j] << " ";
        }
        cout << "\n";
    }
}