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

Tree *bfsToMapParent(Tree *root, unordered_map<Tree *, Tree *> &parentMapping, int start)
{
    queue<Tree *> que;
    que.push(root);
    Tree *target = root;
    Tree *node = root;
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            node = que.front();
            que.pop();

            if (node->left)
            {
                que.push(node->left);
                parentMapping[node->left] = node;
            }

            if (node->right)
            {
                que.push(node->right);
                parentMapping[node->right] = node;
            }

            if (node->data == start)
            {
                target = node;
            }
        }
    }
    return target;
}

int findTime(unordered_map<Tree *, Tree *> parentMapping, Tree *target)
{
    int time = 0;
    unordered_map<Tree *, int> visited;
    visited[target] = 1;
    Tree *node = target;
    queue<Tree *> que;
    que.push(target);

    while (!que.empty())
    {
        bool burn = false;
        int n = que.size();

        for (int i = 0; i < n; i++)
        {
            node = que.front();
            que.pop();

            if (parentMapping[node] && !visited[parentMapping[node]])
            {
                burn = true;
                que.push(parentMapping[node]);
                visited[parentMapping[node]] = 1;
            }

            if (node->left && !visited[node->left])
            {
                burn = true;
                que.push(node->left);
                visited[node->left] = 1;
            }

            if (node->right && !visited[node->right])
            {
                burn = true;
                que.push(node->right);
                visited[node->right] = 1;
            }
        }

        if (burn)
        {
            time++;
        }
    }

    return time;
}

int timeToBurnTree(Tree *root, int start)
{
    // Write your code here
    unordered_map<Tree *, Tree *> parentMapping;
    Tree *target = bfsToMapParent(root, parentMapping, start);

    int time = findTime(parentMapping, target);
    return time;
}

int main()
{

    return 0;
}