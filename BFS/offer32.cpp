// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

//  

// 例如:
// 给定二叉树: [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其层次遍历结果：

// [
//   [3],
//   [9,20],
//   [15,7]
// ]
//  


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
        return res;
    }
};