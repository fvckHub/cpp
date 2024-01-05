#include <iostream>
using namespace std;

/*
给定一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。

每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。

 

示例 1：


输入：root = [1,2,3]
输出：25
解释：
从根到叶子节点路径 1->2 代表数字 12
从根到叶子节点路径 1->3 代表数字 13
因此，数字总和 = 12 + 13 = 25
示例 2：


输入：root = [4,9,0,5,1]
输出：1026
解释：
从根到叶子节点路径 4->9->5 代表数字 495
从根到叶子节点路径 4->9->1 代表数字 491
从根到叶子节点路径 4->0 代表数字 40
因此，数字总和 = 495 + 491 + 40 = 1026
 

提示：

树中节点的数目在范围 [1, 1000] 内
0 <= Node.val <= 9
树的深度不超过 10


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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return qianxu_sum_num(root, sum);
    }

    int qianxu_sum_num(TreeNode* root, int sum) {

        if (root != nullptr)
        {
            sum = sum * 10 + root->val;
            if (root->left == nullptr && root->right == nullptr)
            {
                return sum;
            }
            
            int left_sum = qianxu_sum_num(root->left, sum);
            int right_sum = qianxu_sum_num(root->right, sum);
            return left_sum + right_sum;
        }
        
        return 0;
    }
};

int main() {


    TreeNode * treeNode1 = new TreeNode(1);

    TreeNode * treeNode2 = new TreeNode(2);
    TreeNode * treeNode3 = new TreeNode(3);

    treeNode1->left = treeNode2;
    treeNode1->right = treeNode3;

    Solution solution;
    int res = solution.sumNumbers(treeNode1);

    cout << res << endl;


}