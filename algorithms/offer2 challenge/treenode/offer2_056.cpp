#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
剑指 Offer II 056. 二叉搜索树中两个节点之和

给定一个二叉搜索树的 根节点 root 和一个整数 k , 请判断该二叉搜索树中是否存在两个节点它们的值之和等于 k 。假设二叉搜索树中节点的值均唯一。

 

示例 1：

输入: root = [8,6,10,5,7,9,11], k = 12
输出: true
解释: 节点 5 和节点 7 之和等于 12
示例 2：

输入: root = [8,6,10,5,7,9,11], k = 22
输出: false
解释: 不存在两个节点值之和为 22 的节点
 

提示：

二叉树的节点个数的范围是  [1, 104].
-104 <= Node.val <= 104
root 为二叉搜索树
-105 <= k <= 105

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/opLdQZ
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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> tree_stack;
        vector<int> tree_list;
        TreeNode* cur = root;

        while (cur != nullptr || !tree_stack.empty())
        {
            while (cur != nullptr)
            {
                tree_stack.push(cur);
                cur = cur->left;
            }
            
            cur = tree_stack.top();
            tree_stack.pop();

            tree_list.push_back(cur->val);
            cur = cur->right;
        }

        int p1 = 0;
        int p2 = tree_list.size() - 1;


        while (p1 < p2)
        {
            if (tree_list[p1] + tree_list[p2] < k)
            {
                p1++;
            } else if (tree_list[p1] + tree_list[p2] > k)
            {
                p2--;
            } else
            {
                return true;
            }
            
            
        }
        return false;
        
        


    }
};


int main() {


   TreeNode *tn1 = new TreeNode(8);
    TreeNode *tn2 = new TreeNode(6);
    TreeNode *tn3 = new TreeNode(10);
    TreeNode *tn4 = new TreeNode(5);
    TreeNode *tn5 = new TreeNode(7);
    TreeNode *tn6 = new TreeNode(9);
    TreeNode *tn7 = new TreeNode(11);

    tn1->left = tn2;
    tn1->right = tn3;

    tn2->left = tn4;
    tn2->right = tn5;

    tn3->left = tn6;
    tn3->right = tn7;



    

    Solution solution;
    bool res = solution.findTarget(tn1, 22);
    cout << res << endl;

}