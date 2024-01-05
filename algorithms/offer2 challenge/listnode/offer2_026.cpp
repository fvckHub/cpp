#include <iostream>
using namespace std;

/*
剑指 Offer II 026. 重排链表
x
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

 L0 → L1 → … → Ln-1 → Ln 
请将其重新排列后变为：

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1:



输入: head = [1,2,3,4]
输出: [1,4,2,3]
示例 2:



输入: head = [1,2,3,4,5]
输出: [1,5,2,4,3]
 

提示：

链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/LGjMqU
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
    void reorderList(ListNode *head)
    {
        // find mid
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *front = head;
        while (fast)
        {
            if (fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            else
            {
                break;
            }
        }

        ListNode *back = reverseListNode(slow);
        ListNode *mid = slow;
        ListNode *dummy = new ListNode{0, nullptr};

        while (back)
        {
            if (front && front != mid)
            {
                dummy->next = front;
                front = front->next;
                dummy = dummy->next;
            }
            dummy->next = back;
            back = back->next;
            dummy = dummy->next;
        }
    }

    ListNode *reverseListNode(ListNode *head)
    {

        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur)
        {
            head = cur->next;
            cur->next = pre;
            pre = cur;
            cur = head;
        }
        return pre;
    }
};

int main()
{

    ListNode *l1_4 = new ListNode{4, nullptr};
    ListNode *l1_3 = new ListNode{3, l1_4};
    ListNode *l1_2 = new ListNode{2, l1_3};
    ListNode *l1 = new ListNode{1, l1_2};

    Solution solution;
    solution.reorderList(l1);

    while (l1)
    {
        cout << l1->val << endl;
        l1 = l1->next;
    }
    
}