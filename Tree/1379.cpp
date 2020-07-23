class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q; 
        queue<TreeNode*> clone; 
        q.push(original);
        clone.push(cloned);

        while (!q.empty()) {
            TreeNode* cur1 = q.front(); 
            TreeNode* cur2 = clone.front(); 
            q.pop();
            clone.pop();
            if (cur1 == nullptr) continue;

            if (cur1->val == target->val) return cur2;
            q.push(cur1->left);
            q.push(cur1->right);
            clone.push(cur2->left);
            clone.push(cur2->right);
        }
        return nullptr;
    }
};