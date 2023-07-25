// link - https://leetcode.com/problems/merge-sorted-array/submissions/

#include <bits/stdc++.h>
using namespace std;

void mergeArray1(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;
    int n = arr1.size(), m = arr2.size(), i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            ans.push_back(arr1[i++]);
        }
        else
        {
            ans.push_back(arr2[j++]);
        }
    }

    while (i < n)
    {
        ans.push_back(arr1[i++]);
    }

    while (j < m)
    {
        ans.push_back(arr2[j++]);
    }

    cout << "Sorted Array1 "
         << "\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void mergeArray2(vector<int> arr1, vector<int> arr2)
{
    int left = arr1.size() - 1 , m=arr2.size();
    int right = 0;

    // Swap the elements until arr1[left] is smaller than arr2[right]:
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left--], arr2[right++]);
        }
        else
        {
            //rest are sorted.
            break;
        }
    }

    //arr1[] will contain all the smaller elements and arr2[] will contain all the bigger elements

    // Sort arr1[] and arr2[] individually;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};

    mergeArray1(arr1, arr2); // Time - O(m+n) + O(m+n), space - O(m+n)
    mergeArray2(arr1, arr2); // O(min(n, m)) + O(n*logn) + O(m*logm),
}