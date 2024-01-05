#include <iostream>
#include <stack>

using namespace std;

/*
剑指 Offer II 054. 所有大于等于节点的值之和

给定一个二叉搜索树，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。

 

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
 

示例 1：



输入：root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
示例 2：

输入：root = [0,null,1]
输出：[1,null,1]
示例 3：

输入：root = [1,0,2]
输出：[3,3,2]
示例 4：

输入：root = [3,2,4,1]
输出：[7,9,4,10]
 

提示：

树中的节点数介于 0 和 104 之间。
每个节点的值介于 -104 和 104 之间。
树中的所有值 互不相同 。
给定的树为二叉搜索树。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/w6cpku
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
    int total = 0;
    int last = 0;
public:
    TreeNode *convertBST(TreeNode *root)
    {
        count(root);
        last = total;
        changeVal(root);
        return root;
    }

    void count(TreeNode *root)
    {
        if (root != nullptr)
        {
            count(root->left);
            total += root->val;
            count(root->right);
        }
    }

    void changeVal(TreeNode *root)
    {
        if (root != nullptr)
        {
            changeVal(root->left);
            int cur_val = root->val;
            root->val = last;
            last = last - cur_val;
            changeVal(root->right);
        }
    }
};

int main()
{

    TreeNode *tn1 = new TreeNode(4);
    TreeNode *tn2 = new TreeNode(1);
    TreeNode *tn3 = new TreeNode(6);
    TreeNode *tn4 = new TreeNode(0);
    TreeNode *tn5 = new TreeNode(2);
    TreeNode *tn6 = new TreeNode(5);
    TreeNode *tn7 = new TreeNode(7);
    TreeNode *tn8 = new TreeNode(3);
    TreeNode *tn9 = new TreeNode(8);

    tn1->left = tn2;
    tn1->right = tn3;

    tn2->left = tn4;
    tn2->right = tn5;

    tn3->left = tn6;
    tn3->right = tn7;

    tn5->right = tn8;
    tn7->right = tn9;

    

    Solution solution;
    TreeNode *res = solution.convertBST(tn1);
}