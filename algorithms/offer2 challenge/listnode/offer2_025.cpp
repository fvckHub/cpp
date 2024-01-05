#include <iostream>
using namespace std;

/*
剑指 Offer II 025. 链表中的两数相加
给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

可以假设除了数字 0 之外，这两个数字都不会以零开头。

 

示例1：



输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]
示例2：

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[8,0,7]
示例3：

输入：l1 = [0], l2 = [0]
输出：[0]
 

提示：

链表的长度范围为 [1, 100]
0 <= node.val <= 9
输入数据保证链表代表的数字无前导 0
 

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseListNode(l1);
        l2 = reverseListNode(l2);
        bool up = false;
        ListNode *res = nullptr;
        ListNode *cur;
        while (l1 || l2 || up)
        {

            int val;
            if (l1)
            {
                val = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                val = l2->val + val;
                l2 = l2->next;
            }
            if (up)
            {
                val++;
                up = false;
            }
            up = val / 10;
            val = val % 10;

            ListNode *add = new ListNode(val, nullptr);
            val = 0;
            if (res)
            {
                cur->next = add;
                cur = cur->next;
            }
            else
            {
                res = add;
                cur = res;
            }
        }
        return reverseListNode(res);
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
    ListNode *l1_4 = new ListNode{3, nullptr};
    ListNode *l1_3 = new ListNode{4, l1_4};
    ListNode *l1_2 = new ListNode{2, nullptr};
    ListNode *l1 = new ListNode{9, nullptr};

    Solution solution;
    // ListNode *l1_rev = solution.reverseListNode(l1);

    ListNode *l2_3 = new ListNode{4, nullptr};
    ListNode *l2_2 = new ListNode{6, nullptr};
    ListNode *l2 = new ListNode{9, nullptr};

    // ListNode *l2_rev = solution.reverseListNode(l2);

    // while (l1_rev)
    // {
    //     cout << l1_rev->val << endl;
    //     l1_rev = l1_rev->next;
    // }
    // cout << "-------------" << endl;
    // while (l2_rev)
    // {
    //     cout << l2_rev->val << endl;
    //     l2_rev = l2_rev->next;
    // }
    cout << "-------------" << endl;
    ListNode *res = solution.addTwoNumbers(l1, l2);
    while (res)
    {
        cout << res->val << endl;
        res = res->next;
    }


}