#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

bool compare (meeting m1,meeting m2){
    if(m1.end<m2.end){
        return true; // fisrt meeting end point is less
    }else if(m1.end>m2.end){
        return false; // fisrt meeting end point is greater
    }else if(m1.pos<m2.pos){
        return true; // if end point is equal sort base on index
    }else{
        return false;
    }
}

vector<int> maxMeetings(vector<int> &start,vector<int> &end){
    int n = start.size();
    vector<meeting> meets(n);
    vector<int>ans;

    for(int i=0;i<n;i++){
        meets[i].start = start[i];
        meets[i].end = end[i];
        meets[i].pos = i+1;
    }

    sort(meets.begin(),meets.end(),compare);

    ans.push_back(meets[0].pos);
    int maxLimit = meets[0].end;

    for(int i=1;i<n;i++){
        if(meets[i].start>maxLimit){
            maxLimit = meets[i].end;
            ans.push_back(meets[i].pos);
        }
    }

    return ans;

    // Time complecity O(NlogN) and space O(N)
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    vector<int> res = maxMeetings(start, end);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}