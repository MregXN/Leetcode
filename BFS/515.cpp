// 您需要在二叉树的每一行中找到最大的值。

// 示例：

// 输入: 

//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 

// 输出: [1, 3, 9]


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int maxvalue = INT_MIN;
            for(int i = 0 ;i<size;i++)
            {
                TreeNode*  cur = q.front();
                q.pop();
                
                maxvalue =  max(cur->val,maxvalue);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }

            res.emplace_back(maxvalue);
        } 

        return res;
    }
};