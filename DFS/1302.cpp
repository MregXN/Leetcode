// 给你一棵二叉树，请你返回层数最深的叶子节点的和。

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int reslevel = 0 ;
        int res = 0;
        queue<pair<int,TreeNode*>> q;

        q.push({0,root});

        while(!q.empty())
        {
            auto level = q.front().first;
            auto ptr = q.front().second;
            q.pop();
            if( level != reslevel)
            {
                reslevel = level;
                res = 0;
            }
            res += ptr->val;
            if( ptr->left ) q.push({level +1 ,ptr->left});
            if( ptr->right ) q.push({level+1, ptr->right});

        }
        return res;
    }
};