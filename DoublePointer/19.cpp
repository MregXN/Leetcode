// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

// 示例：

// 给定一个链表: 1->2->3->4->5, 和 n = 2.

// 当删除了倒数第二个节点后，链表变为 1->2->3->5.
// 说明：

// 给定的 n 保证是有效的。

// 进阶：

// 你能尝试使用一趟扫描实现吗？


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode temp(0) ;
        ListNode* temp_head = &temp;
        temp_head -> next = head;

        ListNode* res =temp_head;
        ListNode* pos = temp_head;

        while(n--)  pos = pos->next;

        while(pos && pos->next)
        {
            pos = pos->next;
            res = res->next;
        }
        res->next = res->next->next;
        return temp_head -> next ;
    }
};
