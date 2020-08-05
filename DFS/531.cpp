// 给定一个二叉树，在树的最后一行找到最左边的值。

// 示例 1:

// 输入:

//     2
//    / \
//   1   3

// 输出:
// 1
//  

// 示例 2:

// 输入:

//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7

// 输出:
// 7
//  

// 注意: 您可以假设树（即给定的根节点）不为 NULL。

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int resfloor = 0,res = root->val;
        queue<pair<TreeNode*,int>> q; // <层数，balance> 
        q.push({root,0});
        while(!q.empty())
        {
            auto floor = q.front().second;
            auto ptr = q.front().first;
            q.pop();
            
            if(floor > resfloor)
            {
                resfloor = floor;
                res = ptr->val;
            }
            if( ptr->left ) q.push({ptr->left,floor+1});
            if( ptr->right ) q.push({ptr->right,floor+1});
        }
        return res;
    }
};