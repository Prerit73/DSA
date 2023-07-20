
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr, int n)
{
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

// 2nd
int maxSubArray2(vector<int> &nums)
{
    int max_ = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        max_ = max(nums[i], max_ + nums[i]);
        ans = max(ans, max_);
    }
    return ans;
}

//3rd

long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i; // starting index

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // printing the subarray:
    cout << "The subarray is: ";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return maxi;
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();
    int maxSum = maxSubarraySum(arr, n); // O(n2)
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
