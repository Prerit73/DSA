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

int dfs(Tree *root, int &maxSum)
{
    if (!root)
    {
        return 0;
    }

    int left = max(dfs(root->left, maxSum), 0);
    int right = max(dfs(root->right, maxSum), 0);

    maxSum = max(maxSum, root->data + left + right);

    return root->data + max(left, right);
}

int maxPathSum(Tree *root)
{
    int maxSum = root->data;
    dfs(root, maxSum);
    return maxSum;
}

int main()
{
}