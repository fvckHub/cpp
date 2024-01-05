#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
剑指 Offer II 046. 二叉树的右侧视图

给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

 

示例 1:



输入: [1,2,3,null,5,null,4]
输出: [1,3,4]
示例 2:

输入: [1,null,3]
输出: [1,3]
示例 3:

输入: []
输出: []
 

提示:

二叉树的节点个数的范围是 [0,100]
-100 <= Node.val <= 100 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/WNC0Lk
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
public:
    vector<int> rightSideView(TreeNode *root)
    {

        queue<TreeNode *> node_queue;
        vector<int> res;

        if (root == nullptr)
        {
            return {};
        }

        node_queue.push(root);
        res.push_back(root->val);

        while (!node_queue.empty())
        {
            int layer_size = node_queue.size();

            int right_view = 0;
            while (layer_size > 0)
            {
                TreeNode *front_node = node_queue.front();
                node_queue.pop();
                if (front_node->left != nullptr)
                {
                    right_view = front_node->left->val;
                    node_queue.push(front_node->left);
                }

                if (front_node->right != nullptr)
                {
                    right_view = front_node->right->val;
                    node_queue.push(front_node->right);
                }
                layer_size--;
                
            }
            if (!node_queue.empty())
            {
                res.push_back(right_view);
            }
            
            
        }
        return res;
        
    }
};

int main() {

    TreeNode *root = new TreeNode(1);

    TreeNode *l1 = new TreeNode(2);
    TreeNode *l2 = new TreeNode(3);
    TreeNode *l3 = new TreeNode(5);
    TreeNode *l4 = new TreeNode(4);
    l1->right = l3;
    l2->right = l4;
    root->left = l1;
    root->right = l2;



    Solution solution;
    vector<int> res = solution.rightSideView(root);
    for (int &v : res)
    {
        cout << v << endl;
    }
    
}