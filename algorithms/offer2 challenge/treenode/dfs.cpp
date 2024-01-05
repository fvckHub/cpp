#include <vector>
#include <queue>
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Dfs
{
public:
    vector<TreeNode *> dfs(TreeNode *root, vector<TreeNode *> &res)
    {
        vector<TreeNode *> result;
        dfs(root, result);
        return res;
    }

    void zhongxu(TreeNode *root, vector<TreeNode *> &res)
    {
        if (root != nullptr)
        {
            dfs(root->left, res);
            res.push_back(root);
            dfs(root->right, res);
        }
    }

    void qianxu(TreeNode *root, vector<TreeNode *> &res)
    {
        if (root != nullptr)
        {
            res.push_back(root);
            dfs(root->left, res);
            dfs(root->right, res);
        }
    }

    void houxu(TreeNode *root, vector<TreeNode *> &res) {
        if (root != nullptr)
        {
            dfs(root->left, res);
            dfs(root->right, res);
            res.push_back(root);
        }
        
    }



    vector<int> dfs_zhongxu(TreeNode *root)
    {

        stack<TreeNode *> tree_stack;
        vector<int> res;
        TreeNode *cur = root;
        while (cur != nullptr || !tree_stack.empty())
        {
            while (cur != nullptr)
            {
                tree_stack.push(cur);
                cur = cur->left;
            }

            cur = tree_stack.top();
            tree_stack.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }

    vector<int> dfs_qianxu(TreeNode *root)
    {
        vector<int> res = {};
        stack<TreeNode *> tree_stack;
        TreeNode *cur = root;

        while (cur != nullptr || !tree_stack.empty())
        {
            while (cur != nullptr)
            {
                tree_stack.push(cur);
                res.push_back(tree_stack.top()->val);
                cur = cur->left;
            }

            cur = tree_stack.top();
            tree_stack.pop();
            cur = cur->right;
        }
        return res;
    }

    vector<int> dfs_houxu(TreeNode *root) {
        stack<TreeNode*> tree_stack;
        vector<int> res;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur != nullptr || !tree_stack.empty())
        {
            
            while (cur != nullptr)
            {
                tree_stack.push(cur);
                cur = cur->left;
            }
            
            cur = tree_stack.top();
            if (cur->right != nullptr && cur->right != pre)
            {
                cur = cur->right;
            } else {
                tree_stack.pop();
                res.push_back(cur->val);
                pre = cur;
                cur = nullptr;
            }

        }
        return res;
        
    }

};

int main()
{

    TreeNode *tn1 = new TreeNode(1);
    TreeNode *tn2 = new TreeNode(2);
    TreeNode *tn3 = new TreeNode(3);
    TreeNode *tn4 = new TreeNode(4);
    TreeNode *tn5 = new TreeNode(5);
    TreeNode *tn6 = new TreeNode(6);
    TreeNode *tn7 = new TreeNode(7);
    TreeNode *tn8 = new TreeNode(8);

    tn2->left = tn4;
    tn2->right = tn5;

    tn5->right = tn8;
    tn3->left = tn6;
    tn3->right = tn7;

    tn1->left = tn2;
    tn1->right = tn3;


    Dfs dfs;
    // vector<TreeNode*> res = dfs.zhongxu(tn1);
    // for (TreeNode* &r : res)
    // {
    //     cout << r->val << endl;
    // }

    // vector<int> res1 = dfs.dfs_stack(tn1);

    // for (int &i : res1)
    // {
    //     cout << i << endl;
    // }

    vector<int> res = dfs.dfs_qianxu(tn1);
    for (int &i : res)
    {
        cout << i << endl;
    }
}