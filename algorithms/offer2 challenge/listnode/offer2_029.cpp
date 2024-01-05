#include <iostream>
using namespace std;

/*
剑指 Offer II 029. 排序的循环链表

给定循环单调非递减列表中的一个点，写一个函数向这个列表中插入一个新元素 insertVal ，使这个列表仍然是循环升序的。

给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。

如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。

如果列表为空（给定的节点是 null），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。

 

示例 1：


 

输入：head = [3,4,1], insertVal = 2
输出：[3,4,1,2]
解释：在上图中，有一个包含三个元素的循环有序列表，你获得值为 3 的节点的指针，我们需要向表中插入元素 2 。新插入的节点应该在 1 和 3 之间，插入之后，整个列表如上图所示，最后返回节点 3 。


示例 2：

输入：head = [], insertVal = 1
输出：[1]
解释：列表为空（给定的节点是 null），创建一个循环有序列表并返回这个节点。
示例 3：

输入：head = [1], insertVal = 0
输出：[1,0]

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

*/
class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

class Solution
{
public:
    Node *insert(Node *head, int insertVal)
    {
        Node *ori = head;
        Node *insertNode = new Node(insertVal);
        if (!head)
        {
            insertNode->next = insertNode;
            return insertNode;
        }
        Node *maxNode = head;
        while (head)
        {

            if ((head->val < insertVal && (head->next->val > insertVal || head->next->val < head->val)) || head->val == insertVal)
            {
                Node *temp = head->next;
                head->next = insertNode;
                insertNode->next = temp;
                break;
            }

            if (head->val > maxNode->val)
            {
                maxNode = head;
            }

            if (head->next == ori)
            {
                Node *temp = maxNode->next;
                maxNode->next = insertNode;
                insertNode->next = temp;
                break;
            }

            head = head->next;
        }
        return ori;
    }
};

int main()
{

    Node *node1 = new Node(1);
    Node *node2 = new Node(3);
    Node *node3 = new Node(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    Solution solution;
    Node *res = solution.insert(node1, 3);

    for (size_t i = 0; i < 4; i++)
    {
        cout << res->val << endl;
        res = res->next;
    }
}