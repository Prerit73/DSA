//link https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    // need a break point. (If we rearrange the number from back we will not get a next premutaion, till we have a increasing order from end.)
    int ind = -1, n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i + 1] > nums[i])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    //Find the next greater element. (Becase less one will not give next permutation)
    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    // we have increasing order from end, so if we reverse we will get the minumum.

    reverse(nums.begin() + ind + 1, nums.end());
}

int main()
{
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};

    // next_permutation(nums.begin(),nums.end());  //using in-built function

    nextPermutation(nums);

    return 0;
}
