#include <bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s)
{
    int n = s.length();
    for (int l = n / 2; l >= 1; l--)
    {
        if (n % l == 0)
        {
            int length = n / l;
            string SubString = s.substr(0, l);
            string newString = "";
            while (length)
            {
                newString += SubString;
                length--;
            }
            if (newString == s)
                return true;
        }
    }
    return false;
}