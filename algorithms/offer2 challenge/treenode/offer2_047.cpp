#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
剑指 Offer II 047. 二叉树剪枝

给定一个二叉树 根节点 root ，树的每个节点的值要么是 0，要么是 1。请剪除该二叉树中所有节点的值为 0 的子树。

节点 node 的子树为 node 本身，以及所有 node 的后代。

 

示例 1:

输入: [1,null,0,0,1]
输出: [1,null,0,null,1] 
解释: 
只有红色节点满足条件“所有不包含 1 的子树”。
右图为返回的答案。


示例 2:

输入: [1,0,1,0,0,0,1]
输出: [1,null,1,null,1]
解释: 


示例 3:

输入: [1,1,0,1,1,0,1,0]
输出: [1,1,0,1,1,null,1]
解释: 


 

提示:

二叉树的节点个数的范围是 [1,200]
二叉树节点的值只会是 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/pOCWxh
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        stack<TreeNode*> tree_stack;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

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

                if (cur->val == 0 && cur->right == nullptr && cur->left == nullptr)
                {
                    if (!tree_stack.empty())
                    {
                        TreeNode *parent = tree_stack.top();
                        if (parent->left == cur)
                        {
                            parent->left = nullptr;
                        } else if (parent->right == cur)
                        {
                            parent->right = nullptr;
                        }
                    } else {
                        return nullptr;
                    }
                }
                
                pre = cur;
                cur = nullptr;
            }
            
        }
        return root;
        
    }
};

int main() {

    TreeNode *tn1 = new TreeNode(1);
    TreeNode *tn2 = new TreeNode(0);
    TreeNode *tn3 = new TreeNode(1);
    TreeNode *tn4 = new TreeNode(0);
    TreeNode *tn5 = new TreeNode(0);
    TreeNode *tn6 = new TreeNode(0);
    TreeNode *tn7 = new TreeNode(1);

    tn2->left = tn4;
    tn2->right = tn5;

    tn3->left = tn6;
    tn3->right = tn7;

    tn1->left = tn2;
    tn1->right = tn3;


    Solution solution;
    TreeNode * res = solution.pruneTree(tn1);

    
}
