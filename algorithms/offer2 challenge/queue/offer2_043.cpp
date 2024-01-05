#include <iostream>
#include <queue>

using namespace std;


/*
剑指 Offer II 043. 往完全二叉树添加节点

完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大，第 n 层有 2n-1 个节点）的，并且所有的节点都尽可能地集中在左侧。

设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：

CBTInserter(TreeNode root) 使用根节点为 root 的给定树初始化该数据结构；
CBTInserter.insert(int v)  向树中插入一个新节点，节点类型为 TreeNode，值为 v 。使树保持完全二叉树的状态，并返回插入的新节点的父节点的值；
CBTInserter.get_root() 将返回树的根节点。
 

示例 1：

输入：inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
输出：[null,1,[1,2]]
示例 2：

输入：inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
输出：[null,3,4,[1,2,3,4,5,6,7,8]]


*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
    
public:
    TreeNode* rootNode;
    queue<TreeNode*> node_queue;
    CBTInserter(TreeNode* root) {
        rootNode = root;
        node_queue.push(rootNode);
        while (node_queue.front()->left != nullptr && node_queue.front()->right != nullptr)
        {
            TreeNode* front_node = node_queue.front();
            node_queue.push(front_node->left);
            node_queue.push(front_node->right);
            node_queue.pop();
        }

    }
    
    int insert(int v) {
        TreeNode* front_node = node_queue.front();

        TreeNode* TreeNode_new = new TreeNode(v);
        if (front_node->left == nullptr)
        {
            front_node->left=TreeNode_new;
        } else {
            front_node->right=TreeNode_new;
            node_queue.push(front_node->left);
            node_queue.push(front_node->right);
            node_queue.pop();
        }
        return front_node->val;
    }
    
    TreeNode* get_root() {
        return rootNode;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

int main() {

    TreeNode *treeNode = new TreeNode(1);

    CBTInserter cbt(treeNode);
    

}