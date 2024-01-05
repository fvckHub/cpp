#include <iostream>
using namespace std;

/*
剑指 Offer II 021. 删除链表的倒数第 n 个结点

给定一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/SLwz0R
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *node1 = head;
        ListNode *node2 = head;
        ListNode *dummy_node = new ListNode;
        *dummy_node = {0, head};
        ListNode *node2_pre = dummy_node;
        for (int i = 0; i < n - 1; i++)
        {
            if (head->next != nullptr)
            {
                node1 = node1->next;
            }
            else if (i != n - 2)
            {
                return head;
            }
        }

        // delete node

        while (node1->next != nullptr)
        {
            node1 = node1->next;
        
            node2 = node2->next;
            node2_pre = node2_pre->next;
        }

        
        
        node2_pre->next = node2->next;

        return dummy_node->next;
    }
};

int main()
{

    Solution solution;
    ListNode *head = new ListNode;
    ListNode *listNode2 = new ListNode;
    ListNode *listNode3 = new ListNode;
    ListNode *listNode4 = new ListNode;
    ListNode *listNode5 = new ListNode;

    *head = {1, listNode2};
    *listNode2 = {2, listNode3};
    *listNode3 = {3};
    *listNode4 = {4, listNode5};
    *listNode5 = {5};

    ListNode *result = solution.removeNthFromEnd(head, 3);

    while (result != nullptr)
    {
        cout << result->val << endl;
        result = result->next;
    }
}