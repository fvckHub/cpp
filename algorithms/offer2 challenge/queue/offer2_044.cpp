#include <queue>
#include <iostream>
using namespace std;


/*
剑指 Offer II 044. 二叉树每层的最大值

给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

 

示例1：

输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
解释:
          1
         / \
        3   2
       / \   \  
      5   3   9 
示例2：

输入: root = [1,2,3]
输出: [1,3]
解释:
          1
         / \
        2   3
示例3：

输入: root = [1]
输出: [1]
示例4：

输入: root = [1,null,2]
输出: [1,2]
解释:      
           1 
            \
             2     
示例5：

输入: root = []
输出: []

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/hPov7L
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
    vector<int> largestValues(TreeNode* root) {
        
        queue<TreeNode*> node_queue;
        vector<int> res;
        
        if (!root)
        {
            return {};
        }
        int cur = 1;
        int next = 0;
        int max = INT_MIN;
        node_queue.push(root);

        while (!node_queue.empty())
        {
            if (node_queue.front()->left != nullptr)
            {
                next++;
                node_queue.push(node_queue.front()->left);
            }
            if (node_queue.front()->right != nullptr)
            {
                next++;
                node_queue.push(node_queue.front()->right);
            }

            TreeNode *curNode = node_queue.front();
            node_queue.pop();
            max = curNode->val > max ? curNode->val : max;

            cur--;

            if (!cur)
            {
                res.push_back(max);
                cur = next;
                next = 0;
                max = INT_MIN;
            }
            
            
        }
        return res;
        
    }
};

int main() {

    Solution solution;

    TreeNode *root = new TreeNode(0);
    TreeNode *son = new TreeNode(-1);
    root->left = son;

    vector<int> res = solution.largestValues(root);

    for (int &i : res)
    {
        cout << i << endl;
    }
    

}