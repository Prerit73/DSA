#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
    }

    Node(int data1, Node *next)
    {
        data = data1;
        next = next;
    }
};

int main(){
    return 0;
}
