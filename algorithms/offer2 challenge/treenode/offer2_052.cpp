#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
剑指 Offer II 052. 展平二叉搜索树

给你一棵二叉搜索树，请 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。

 

示例 1：



输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
示例 2：



输入：root = [5,1,7]
输出：[1,null,5,null,7]
 

提示：

树中节点数的取值范围是 [1, 100]
0 <= Node.val <= 1000

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        stack<TreeNode *> tree_stack;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        TreeNode *res = nullptr;

        while (cur != nullptr || !tree_stack.empty())
        {

            while (cur != nullptr)
            {
                tree_stack.push(cur);
                cur = cur->left;
            }
            cur = tree_stack.top();
            tree_stack.pop();
            if (pre == nullptr) {
                res = cur;
            } else {
                pre->right = cur;
            }
            cur->left = nullptr;
            pre = cur;
            cur = cur->right;
            
        }

        return res->right;
    }
};
