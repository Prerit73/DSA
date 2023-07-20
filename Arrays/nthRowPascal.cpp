#include <bits/stdc++.h>
using namespace std;

void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans *= (n - i);
        ans /= i;
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    pascalTriangle(n);   //1 4 6 4 1
    return 0;
}