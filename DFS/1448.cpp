给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。



class Solution {
private:
    int res= 0;
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        dfs(root,root->val);
        return res;
        
    }

    void dfs(TreeNode* root, int max1)
    {
        if(!root) return ;
        if(root->val >= max1) {
            res++;
            max1 = root->val;
        } 

        dfs(root->left, max1);
        dfs(root->right, max1);
        return;
    }
};