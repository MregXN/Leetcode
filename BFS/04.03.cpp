// 给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。

//  

// 示例：

// 输入：[1,2,3,4,5,null,7,8]

//         1
//        /  \ 
//       2    3
//      / \    \ 
//     4   5    7
//    /
//   8

// 输出：[[1],[2,3],[4,5,7],[8]]
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if(!tree) return {}; 
        queue<TreeNode*> q;
        vector<ListNode*> res;
        q.push( tree);

        while(!q.empty())
        {
            int size = q.size();
            ListNode* h = new ListNode(0);
            ListNode* k = h;

            for(int i = 0 ; i < size ; i ++)
            {
                TreeNode* front =  q.front();
                if(!i) h->val = front->val
                else
                {
                    ListNode* cur = new ListNode(front->val);
                    k->next = cur;
                    k  = k->next;
                }
                q.pop();

                if(front->left) q.push( front->left);
                if(front->right) q.push( front->right);
            }

             res.push_back(h);
        }
        return res;
    }
};