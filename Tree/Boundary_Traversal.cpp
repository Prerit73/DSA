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

bool isleaf(Tree *root)
{
    if (!root->left and !root->right)
        return true;

    return false;
}

void addLeftBoundary(Tree *root, vector<int> &ans)
{
    Tree *node = root->left;
    while (node)
    {
        if (!isleaf(node))
        {
            ans.push_back(node->data);
        }

        if (node->left)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
}

void addLeafBoundary(Tree *root, vector<int> &ans)
{
    if (isleaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
    {
        addLeafBoundary(root->left, ans);
    }
    if (root->right)
    {
        addLeafBoundary(root->right, ans);
    }
}

void addRightBoundary(Tree *root, vector<int> &ans)
{
    Tree *node = root->right;
    vector<int> temp;
    while (node)
    {
        if (!isleaf(node))
        {
            temp.push_back(node->data);
        }

        if (node->right)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> boundary(Tree *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    if (!isleaf(root))
    {
        ans.push_back(root->data);
    }

    addLeftBoundary(root, ans);
    addLeafBoundary(root, ans);
    addRightBoundary(root, ans);

    return ans;
}

int main()
{
    return 0;
}