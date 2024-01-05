#include <iostream>
#include <unordered_map>

using namespace std;

/*
剑指 Offer II 050. 向下的路径节点之和

给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

 

示例 1：



输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
示例 2：

输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
 

提示:

二叉树的节点个数的范围是 [0,1000]
-109 <= Node.val <= 109 
-1000 <= targetSum <= 1000 
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/6eUYwP
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

private:
    unordered_map<int, int> um; // key存储到该节点时累加的值，value为该累计值存在的累加的节点个数
    int res = 0;

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        um.insert(make_pair(0,1));
        dfs(root, 0, targetSum);
        return res;
    }

    void dfs(TreeNode *root, int sum, int targetSum)
    {
        if (!root)
            return;
        sum += root->val;
        if (um.count(sum - targetSum))
            res += um[sum - targetSum];
        if (um.count(sum))
            um[sum]++;
        else
            um.insert(make_pair(sum, 1));
        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
        um[sum]--; // 当该函数结束时，程序将回到节点的父节点，也就是说，在函数结束之前需要将当前节点从路径中删除，从根节点到当前节点累加的节点值之和也要从哈希表map中删除
    }
};