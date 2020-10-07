// 给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。

// 每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。

// 返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。

// 注意：在下面的示例中，诸如 [2,1,5] 这样的输入（不是输出）是链表的序列化表示，其头节点的值为 2，第二个节点值为 1，第三个节点值为 5 。

//  

// 示例 1：

// 输入：[2,1,5]
// 输出：[5,5,0]
// 示例 2：

// 输入：[2,7,4,3,5]
// 输出：[7,0,5,5,0]
// 示例 3：

// 输入：[1,7,5,1,9,2,5,1]
// 输出：[7,9,9,9,0,5,0,0]
//  

// 提示：

// 对于链表中的每个节点，1 <= node.val <= 10^9
// 给定列表的长度在 [0, 10000] 范围内

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head) return {};
        ListNode* target_node = head;
        ListNode* cur_node = head;
        vector<int> res;

        while(cur_node)
        {
            if(cur_node->val > target_node->val)
            {
                while(target_node != cur_node)
                {
                    res.emplace_back(cur_node->val);
                    target_node = target_node->next;
                }
            }
            cur_node = cur_node->next;
            if(!cur_node)
            {
                res.emplace_back(0);
                target_node = target_node->next;
                cur_node = target_node;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        int count = 0; //计数，作为下标
        vector<int> result;
        stack<pair<int, int>> tmp; //first为val，second为下标
        while (head)
        {
            result.push_back(0); //给result数组后面+0，1为保证长度，2是默认值（后无更大的值的话）为0
            while (!tmp.empty() &&
                   head->val > tmp.top().first) //栈不为空且head指针的val值大于栈顶的元素的值
            {
                result[tmp.top().second] = head->val; //result数组修改，满足题意要求的最大值，然后出栈，继续循环
                tmp.pop();
            }
            tmp.push(make_pair(head->val, count++)); //count++计数
            head = head->next; //下一个节点
        }
        return result;
    }
};
