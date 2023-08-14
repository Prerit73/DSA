#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> p;

    for (int i = 0; i < nums.size(); i++)
    {
        p.push(nums[i]);
        if (p.size() > k)
        {
            p.pop();
        }
    }
    return p.top();
}

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 2;
    int ans = findKthLargest(nums, k);
}