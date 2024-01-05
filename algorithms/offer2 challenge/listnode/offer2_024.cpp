#include <iostream>
using namespace std;

/*
剑指 Offer II 024. 反转链表

给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。

 

示例 1：


输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：


输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/UHnkqh
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *target;
        ListNode *temp;
        if (head == NULL)
        {
            return nullptr;
        }
        
        target = head->next;
        head->next = NULL;
        while (head != nullptr && target != nullptr)
        {

            temp = target->next;
            target->next = head;
            head = target;
            target = temp;
        }
        return head;
    }

    ListNode* reverseList2(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseList3(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList3(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

};

int main() {
    Solution solution;
    ListNode *head = new ListNode;
    ListNode *listNode2 = new ListNode;
    ListNode *listNode3 = new ListNode;
    ListNode *listNode4 = new ListNode;
    ListNode *listNode5 = new ListNode;

    *head = {1, listNode2};
    *listNode2 = {2, listNode3};
    *listNode3 = {3, listNode4};
    *listNode4 = {4, listNode5};
    *listNode5 = {5};

    ListNode *result = solution.reverseList3(head);

    while (result != nullptr)
    {
        cout << result->val << endl;
        result = result->next;
    }
}