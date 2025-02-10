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

bool isSameTree(Tree *p, Tree *q)
{
    if (!p && !q)
    {
        return true;
    }

    if (!p || !q || p->data != q->data)
    {
        return false;
    }

    return isSameTree(p->left, q->right) && isSameTree(p->right, q->right);

    // Using DFS we will use 2 queue with same logic
    /*
    while (!q1.empty() && !q2.empty())
    {
        Tree *nodeP = q1.front();
        q1.pop();
        Tree *nodeQ = q2.front();
        q2.pop();

        if (!nodeP && !nodeQ)
            continue;
        if (!nodeP || !nodeQ || nodeP->val != nodeQ->val)
            return false;

        q1.push(nodeP->left);
        q1.push(nodeP->right);
        q2.push(nodeQ->left);
        q2.push(nodeQ->right);
    }*/
}

bool isSubtree(Tree *root, Tree *subRoot)
{
    if (!subRoot)
    {
        return true;
    }

    if (!root)
    {
        return false;
    }

    if (isSameTree(root, subRoot))
    {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    return 0;
}