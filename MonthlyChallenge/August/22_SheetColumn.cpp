#include <bits/stdc++.h>
using namespace std;
string convertToTitle(int columnNumber)
{
    string ans = "";
    while (columnNumber)
    {
        int temp = (columnNumber - 1) % 26;
        ans.push_back('A' + temp);
        columnNumber = (columnNumber - 1) / 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}