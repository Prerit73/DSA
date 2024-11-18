#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
    for (int i = 1; i <= m; i++)
    {
        long long nthPower = pow(i, n);
        if (nthPower == m)
        {
            return i;
        }
    }

    return -1;
}

int checkNumber(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = ans * mid;
        if (ans > m)
        {
            return 2;
        }
    }
    if (ans == m)
    {
        return 0;
    }

    return 1;
}

int NthRootOptimise(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        int num = checkNumber(mid, n, m);
        if (num == 0)
        {
            return mid;
        }

        if (num == 1)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);          // O(M)+O(logN)
    int ans2 = NthRootOptimise(n, m); // O(logM)
    cout << "The answer is: " << ans << "\n";
    return 0;
}