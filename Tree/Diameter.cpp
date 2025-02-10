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

int dfs(Tree *root, int &res)
{
    if (!root)
    {
        return 0;
    }

    int left = dfs(root->left, res);
    int right = dfs(root->right, res);
    res = max(res, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(Tree *root)
{
    // get height of left and right subtree for every node and store the max, it will take time of O(N2)
    /*
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diameter = leftHeight + rightHeight;

    return max(diameter, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    */

    /*
     int res = 0;
     dfs(root, res);
     return res;
     */
}

int main()
{
    return 0;
}