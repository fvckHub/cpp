#include <iostream>
using namespace std;

/*
剑指 Offer II 027. 回文链表

给定一个链表的 头节点 head ，请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。

 

示例 1：



输入: head = [1,2,3,3,2,1]
输出: true
示例 2：



输入: head = [1,2]
输出: false
 

提示：

链表 L 的长度范围为 [1, 105]
0 <= node.val <= 9
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/aMhZSa
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
    bool isPalindrome(ListNode *head)
    {
        // 快慢指针 -> get mid
        ListNode *fast = head, *slow = head;

        while (fast)
        {
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            } 
            slow = slow->next;
        }
        
        ListNode *mid = slow;
        ListNode *back = reverseNode(slow);

        while (back)
        {
            if (head->val != back->val)
            {
                return false;
            }
            head = head->next;
            back = back->next;
        }
        
        return true;
    }

    ListNode *reverseNode(ListNode *head) {
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


int main() {


    ListNode *l1_4 = new ListNode{1, nullptr};
    ListNode *l1_3 = new ListNode{2, l1_4};
    ListNode *l1_2 = new ListNode{1, l1_3};
    ListNode *l1 = new ListNode{1, l1_2};

    Solution solution;
    bool res = solution.isPalindrome(l1);

    cout << "result :" << res << endl;

}