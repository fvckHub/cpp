#include <iostream>
#include <unordered_map>
using namespace std;


/*
剑指 Offer II 051. 节点之和最大的路径

路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给定一个二叉树的根节点 root ，返回其 最大路径和，即所有路径上节点值之和的最大值。

 

示例 1：



输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
示例 2：



输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 

提示：

树中节点数目范围是 [1, 3 * 104]
-1000 <= Node.val <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/jC7MId
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
private:

    int max;
    int sum;
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        
        max = INT_MIN;
        return dfs_max(root);


    }

    int dfs_max(TreeNode* root) {

        if (root == nullptr)
        {
            return 0;
        }

        int left_max = dfs_max(root->left);
        left_max = left_max > 0 ? left_max : 0;
        int right_max = dfs_max(root->right);
        right_max = right_max > 0 ? right_max : 0;

        int layer_max = root->val+ left_max + right_max;
        max = layer_max > max ? layer_max : max;
        return root->val+ (left_max > right_max ? left_max : right_max);

    }
};