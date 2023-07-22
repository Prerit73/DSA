// link https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
using namespace std;

void sortArray1(vector<int> &arr, int n)
{
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }

    for (int i = count0; i < count0 + count1; i++)
    {
        arr[i] = 1;
    }

    for (int i = count0 + count1; i < n; i++)
    {
        arr[i] = 2;
    }
}

void sortArray2(vector<int> &arr, int n)
{
    int i = 0, j = 0, k = n - 1;

    while (j <= k)
    {
        if (arr[j] == 0)
        {
            swap(arr[i++], arr[j++]);
        }
        else if (arr[j] == 2)
        {
            swap(arr[j], arr[k--]);
        }
        else
        {
            j++;
        }
    }
}
int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    // sortArray1(arr, n);
    sortArray2(arr, n);

    cout << "Sorted Array " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}