#include <iostream>
using namespace std;

/*
剑指 Offer II 028. 展平多级双向链表
多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给定位于列表第一级的头节点，请扁平化列表，即将这样的多级双向链表展平成普通的双向链表，使所有结点出现在单级双链表中。

 

示例 1：

输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
输出：[1,2,3,7,8,11,12,9,10,4,5,6]
解释：

输入的多级列表如下图所示：



扁平化后的链表如下图：


示例 2：

输入：head = [1,2,null,3]
输出：[1,3,2]
解释：

输入的多级列表如下图所示：

  1---2---NULL
  |
  3---NULL
示例 3：

输入：head = []
输出：[]
 

如何表示测试用例中的多级链表？

以 示例 1 为例：

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
序列化其中的每一级之后：

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
为了将每一级都序列化到一起，我们需要每一级中添加值为 null 的元素，以表示没有节点连接到上一级的上级节点。

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
合并所有序列化结果，并去除末尾的 null 。

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/Qv1Da2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
    Node(int x)
    {
        val = x;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    };
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        tail(head);
        return head;
    }

    Node *tail(Node *head)
    {
        Node *cur = head;
        while (head)
        {
            if (head->child != nullptr)
            {
                Node *temp = nullptr;
                if (head->next)
                {
                    temp = head->next;
                    temp->prev = nullptr;
                }

                head->next = head->child;
                head->child = nullptr;
                head->next->prev = head;

                head = tail(head);
                head->next = temp;
                if (temp)
                {
                    head->next->prev = head;
                }
            }
            cur = head;
            head = head->next;
        }
        return cur;
    }
};

// [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
int main()
{

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = node6;
    node6->next = node5;
    node6->next = nullptr;

    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node *node9 = new Node(9);
    Node *node10 = new Node(10);
    node3->child = node7;
    node7->next = node8;
    node8->prev = node7;
    node8->next = node9;
    node9->prev = node8;
    node9->next = node10;
    node10->prev = node9;
    node10->next = nullptr;

    Node *node11 = new Node(11);
    Node *node12 = new Node(12);
    node8->child = node11;
    node11->next = node12;
    node12->prev = node11;
    node12->next = nullptr;

    Solution solution;
    Node *result = solution.flatten(node1);
    while (result)
    {
        cout << result->val << endl;
        result = result->next;
    }
}