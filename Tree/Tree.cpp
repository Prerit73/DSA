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

void preOrder(Tree *root)
{
    if (!root)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

    // vector<int> preOrder;
    // stack<Tree *> st;
    // st.push(root);

    // while (!st.empty())
    // {
    //     Tree *topElement = st.top();
    //     st.pop();
    //     preOrder.push_back(topElement->data);

    //     if (topElement->right)
    //     {
    //         st.push(topElement->right);
    //     }

    //     if (topElement->left)
    //     {
    //         st.push(topElement->left);
    //     }
    // }
}

void inorder(Tree *root)
{
    vector<int> ans;
    stack<Tree *> st;
    Tree *node = root;
    while (true)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }

        if (st.empty())
        {
            break;
        };
        node = st.top();
        st.pop();
        ans.push_back(node->data);
        node = node->right;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

void postOrder(Tree *root)
{
    stack<Tree *> s1, s2;

    s1.push(root);
    while (s1.size())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);

        if (root->left)
        {
            s1.push(root->left);
        }

        if (root->right)
        {
            s1.push(root->right);
        }
    }

    while (s2.size())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

void levelOrder(Tree *root)
{
    queue<Tree *> que;
    vector<vector<int>> res;

    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        vector<int> levelData;
        for (int i = 0; i < n; i++)
        {
            Tree *frontNode = que.front();
            que.pop();

            levelData.push_back(frontNode->data);

            if (frontNode->left)
            {
                que.push(frontNode->left);
            }

            if (frontNode->right)
            {
                que.push(frontNode->right);
            }
        }
        res.push_back(levelData);
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << "Level" << i + 1 << " ";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Tree *root = new Tree(1);

    root->left = new Tree(2);
    root->right = new Tree(3);

    root->left->left = new Tree(4);
    root->left->right = new Tree(5);

    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    // preOrder(root);

    return 0;
}