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

Tree *invertTree(Tree *root)
{
    if (!root)
    {
        return root;
    }

    /* Tree* node = new Tree(root->data);
    node->right =  invertTree(root->left);
    node->left = invertTree(root->right);
    return node;*/

    /*using Queue
    queue<Tree *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        Tree *node = queue.front();
        queue.pop();
        swap(node->left, node->right);

        if (node->left)
            queue.push(node->left);
        if (node->right)
            queue.push(node->right);
    }

    return root;*/


}

int main()
{
    return 0;
}