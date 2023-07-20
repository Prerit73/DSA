#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}


//2nd solution

vector<vector<int>> generate(int numRows) {
    vector<vector<int>>ans(numRows);
        
    for(int i=0;i<numRows;i++){
        ans[i].resize(i+1);
        ans[i][0]=ans[i][i]=1;
            
        for(int j=1;j<i;j++){
            ans[i][j]=ans[i-1][j] + ans[i-1][j-1];
        }
    }
        
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    vector<vector<int>> ans2 = generate(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}