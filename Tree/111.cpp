// 给定一个二叉树，找出其最小深度。

// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

// 说明: 叶子节点是指没有子节点的节点。

// 示例:

// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最小深度  2.

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {

        int r=0x7fffffff ;

        dfs(root,1,r);
        return root == NULL ? 0:r;
        
    }

    void dfs( TreeNode* root , int len , int& r )
    {
        if( root == NULL)   return;
        else
        {
            if( root->left == NULL && root->right == NULL) r = len <r ? len : r;
            else
            {
                dfs(root->left , len +1 ,r);
                dfs(root->right , len +1 ,r);
            }
        }
        return;
    }
};


