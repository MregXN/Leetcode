// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其自底向上的层次遍历为：

// [
//   [15,7],
//   [9,20],
//   [3]
// ]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        if(!root) return{};
        vector<vector<int>> res;
        vector<int> temp;
        int level_flag = 1;

        queue< pair<TreeNode*,int> > q;
        q.push({root,1});

        while( !q.empty())
        {
            TreeNode* cur = q. front().first;
            int level = q. front().second;
            q.pop();

            if(level_flag != level)
            {
                level_flag = level;
                res.push_back(temp);
                temp.clear();
            }
            temp.push_back( cur-> val);

            if(cur->left) q.push({cur->left,level+1});
            if(cur->right) q.push({cur->right,level+1});
        }
        res.push_back(temp);
        reverse(res.begin(),res.end()); //  反转会比在头部插入来得效率更高
        return res;
    }
};