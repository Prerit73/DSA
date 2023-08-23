#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{

    string ans = "";
    priority_queue<pair<int, char>> pq;

    vector<int> arr(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr[i])
        {
            char ch = i + 'a';
            pq.push(make_pair(arr[i], ch));
        }
    }

    while (pq.size())
    {
        int count = pq.top().first;
        char ch = pq.top().second;
        pq.pop();

        if (pq.size())
        {
            int count2 = pq.top().first;
            char ch2 = pq.top().second;
            pq.pop();

            ans += ch;
            ans += ch2;

            if (count - 1)
            {
                pq.push(make_pair(count - 1, ch));
            }

            if (count2 - 1)
            {
                pq.push(make_pair(count2 - 1, ch2));
            }
        }
        else
        {
            if (count == 1)
            {
                ans += ch;
                return ans;
            }
            else
            {
                return "";
            }
        }
    }
    return ans;
}