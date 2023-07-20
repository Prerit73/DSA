#include <bits/stdc++.h>
using namespace std;

int helper(int c, int r)
{
    long long res = 1;
    int smallest= min(r,c);

    // calculating nCr:
    for (int i = 0; i < smallest; i++) {
        res *= c - i;
        res /= i + 1;
    }
    return res;
}

int main()
{
    cout<<helper(6,3);
}