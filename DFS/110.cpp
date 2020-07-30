// 给定一个二叉树，判断它是否是高度平衡的二叉树。

// 本题中，一棵高度平衡二叉树定义为：

// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

class Solution {

public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return dfs1(root);
    }

    bool dfs1(TreeNode* root)
    {
        if(! root) return true;
        int leftdepth = 0;
        int rightdepth = 0;
        dfs2(root->left,1,leftdepth);
        dfs2(root->right,1,rightdepth);
        return (abs(leftdepth - rightdepth) <=1) && dfs1(root->left) && dfs1(root->right);

    }

    void dfs2(TreeNode* root , int sum , int& depth)
    {
        if(root == NULL) return;
        depth = (sum > depth)? sum:depth;
        dfs2(root->left , sum +1 , depth);
        dfs2(root->right , sum +1 , depth);
        return ;
    }
};


