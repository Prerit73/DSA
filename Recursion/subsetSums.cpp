#include <bits/stdc++.h>
using namespace std;

void subSetSumsHelper(int index, int sum, vector<int> arr, int n, vector<int> &subsetSum)
{
    if (n == index)
    {
        subsetSum.push_back(sum);
        return;
    }

    // element is picked
    subSetSumsHelper(index + 1, sum + arr[index], arr, n, subsetSum);

    // element is not picked
    subSetSumsHelper(index + 1, sum, arr, n, subsetSum);
}

vector<int> subsetSums(vector<int> arr, int n)
{
    vector<int> subSetSum;
    subSetSumsHelper(0, 0, arr, n, subSetSum);
    return subSetSum;

    /*Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. 
    So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

    Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n. */
}

int main()
{
    vector<int> arr = {5, 2, 1};
    vector<int> ans = subsetSums(arr, arr.size());

    sort(ans.begin(), ans.end());
    cout << "The sum of each subset is " << endl;
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;
}