#include <iostream>
#include <queue>

using namespace std;

/*
剑指 Offer II 045. 二叉树最底层最左边的值

给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

 

示例 1:



输入: root = [2,1,3]
输出: 1
示例 2:



输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
 

提示:

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/LwUNpT
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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> node_queue;

        node_queue.push(root);
        int left_bot_min = INT_MIN;
        while (!node_queue.empty())
        {
            int layer_size = node_queue.size();
            int nextLayer = 0;
            left_bot_min = node_queue.front()->val;
            while (layer_size > 0)
            {
                TreeNode* cur = node_queue.front();
                if (cur->left != nullptr)
                {
                    node_queue.push(cur->left);
                    nextLayer++;
                }
                if (cur->right)
                {
                    node_queue.push(cur->right);
                    nextLayer++;
                }
                layer_size--;
                node_queue.pop();
            }
            
        }
        return left_bot_min;

    }
};