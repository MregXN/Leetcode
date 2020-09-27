// 编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。

// 示例:

// 输入: head = 3->5->8->5->10->2->1, x = 5
// 输出: 3->1->2->10->5->5->8

class Solution {
private:
    ListNode temp;
    ListNode* head_2 = &temp;
    ListNode* back = head_2;
    bool flag = false;
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* cur = head;
        while(cur != NULL)
        {
            if(!flag && cur->val >=x) 
            {
                flag = true;
                continue;
            }
            else if(flag)
            {
                if(cur->next && (cur->next->val < x))
                {
                    push_back(cur->next);
                    cur->next = cur->next->next;
                    continue;
                }
            }
            cur = cur->next;
        }

        push_back(head);
        return head_2->next;

    }


    void push_back(ListNode* node)
    {
        back->next = node;
        back = node;
    }
};