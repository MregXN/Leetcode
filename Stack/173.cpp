// 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

// 调用 next() 将返回二叉搜索树中的下一个最小的数。

//  

// 示例：



// BSTIterator iterator = new BSTIterator(root);
// iterator.next();    // 返回 3
// iterator.next();    // 返回 7
// iterator.hasNext(); // 返回 true
// iterator.next();    // 返回 9
// iterator.hasNext(); // 返回 true
// iterator.next();    // 返回 15
// iterator.hasNext(); // 返回 true
// iterator.next();    // 返回 20
// iterator.hasNext(); // 返回 false
//  

// 提示：

// next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。
// 你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。


class BSTIterator {
private:
    queue<int> q ;
public:
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    void dfs(TreeNode* root)
    {
        if(!root) return ;
        dfs(root->left);
        q.push(root->val);
        dfs(root->right);
        return ;
    }
    
    /** @return the next smallest number */
    int next() {
        int res = q.front();
        q.pop();
        return res;

    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();

    }
};
