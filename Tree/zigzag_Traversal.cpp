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

vector<vector<int>> zigzag(Tree *root)
{
    vector<vector<int>> ans;
    if (!root)
    {
        return ans;
    }

    queue<Tree *> queue;
    queue.push(root);

    bool leftToRight = true;

    while (!queue.empty())
    {
        int n = queue.size();
        vector<int> levelData(n);
        for (int i = 0; i < n; i++)
        {
            root = queue.front();
            queue.pop();

            int index = leftToRight ? i : n - i - 1;
            levelData[index] = root->data;
            if (root->left)
            {
                queue.push(root->left);
            }
            if (root->right)
            {
                queue.push(root->right);
            }
        }
        leftToRight = !leftToRight;
        ans.push_back(levelData);
    }
    return ans;
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

    vector<vector<int>> ans = zigzag(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}