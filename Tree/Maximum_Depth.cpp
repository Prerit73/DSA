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

int maxDepth(Tree *root)
{
    if (!root)
    {
        return 0;
    }

    // return 1 + max(maxDepth(root->left), maxDepth(root->right));

    queue<Tree *> queue;
    queue.push(root);

    int level = 0;

    while (!queue.empty())
    {
        int size = queue.size();

        for (int i = 0; i < size; i++)
        {
            root = queue.front();
            queue.pop();

            if (root->left)
            {
                queue.push(root->left);
            }
            if (root->right)
            {
                queue.push(root->right);
            }
        }
        level++;
    }

    return level;
}

int main()
{
    return 0;
}