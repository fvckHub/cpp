#include <iostream>
using namespace std;

/*
剑指 Offer II 022. 链表中环的入口节点

给定一个链表，返回链表开始入环的第一个节点。 从链表的头节点开始沿着 next 指针进入环的第一个节点为环的入口节点。如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

 

示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
 

提示：

链表中节点的数目范围在范围 [0, 104] 内
-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/c32eOV
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return nullptr;
        }

        fast = fast->next->next;
        slow = slow->next;
        while (fast != slow)
        {

            if (fast->next == nullptr || fast->next->next == nullptr)
            {
                return nullptr;
            }
            else
            {
                fast = fast->next->next;
                slow = slow->next;
            }
        }

        ListNode *dummy = head;
        while (slow != dummy)
        {
            dummy = dummy->next;
            slow = slow->next;
        }

        return dummy;
    }
};

int main()
{
    Solution solution;
    ListNode *head = new ListNode;
    ListNode *listNode2 = new ListNode;
    ListNode *listNode3 = new ListNode;
    ListNode *listNode4 = new ListNode;

    *head = {1, listNode2};
    *listNode2 = {2, listNode3};
    *listNode3 = {3, listNode4};
    *listNode4 = {4, listNode2};

    solution.detectCycle(head);
}