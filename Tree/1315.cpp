// 给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：

// 该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
// 如果不存在祖父节点值为偶数的节点，那么返回 0 。

class Solution {
private:
    int sum = 0;
public:
    int sumEvenGrandparent(TreeNode* root) {

        if( root == NULL) return sum;
        else
        {
            if(root-> val %2 == 0 ) addtosum( root) ;
            sumEvenGrandparent(root->left);
            sumEvenGrandparent(root->right);
        }
        
        return sum;
    }


    void addtosum(TreeNode* root )
    {
        if(root->left) 
        {
            if(root->left->left ) sum += root->left->left->val;
            if(root->left->right ) sum += root->left->right->val;

        }
        if( root->right)
        {
            if(root->right->left ) sum += root->right->left->val;
            if(root->right->right ) sum += root->right->right->val;
        }
    }
};