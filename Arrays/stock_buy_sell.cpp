// link https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

// first approach

// Take a variable ans. Run two loop, i=0 and j=i+1. If arr[k] > arr[i] then ans=max(ans,arr[j]-arr[i])

int maxProfit(vector<int> arr)
{
    int minPrice = INT_MAX, maxPro = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    return maxPro;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}