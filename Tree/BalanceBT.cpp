#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;

    Tree()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Tree(int data1)
    {
        data = data1;
        left = NULL;
        right = NULL;
    }
};

int dfsHeight(Tree *root)
{
    if (!root)
    {
        return 0;
    }
    int leftHeight = dfsHeight(root->left);
    int rightHeight = dfsHeight(root->right);
    if (abs(leftHeight - rightHeight) > 1 || leftHeight == -1 || rightHeight == -1)  
    // diff is greater than 1,we will return -1, And if we get -1 from left or right, we donn't need to check for height
    {
        return -1;
    }
    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(Tree *root)
{
    // get height for every node and check the diff, it will take time of O(N2)
    /*
    if (!root)
        return true;

    int left = height(root->left);
    int right = height(root->right);
    if (abs(left - right) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
    */

   //return dfsHeight(root)!=-1
}

int main()
{
    return 0;
}