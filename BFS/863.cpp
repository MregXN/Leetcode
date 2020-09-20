// 给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。

// 返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。

//  

// 示例 1：

// 输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
// 输出：[7,4,1]
// 解释：
// 所求结点为与目标结点（值为 5）距离为 2 的结点，
// 值分别为 7，4，以及 1



// 注意，输入的 "root" 和 "target" 实际上是树上的结点。
// 上面的输入仅仅是对这些对象进行了序列化描述。
//  

// 提示：

// 给定的树是非空的。
// 树上的每个结点都具有唯一的值 0 <= node.val <= 500 。
// 目标结点 target 是树上的结点。
// 0 <= K <= 1000.
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
private:
    unordered_map<TreeNode*, long long > m;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root,0);
        vector<int> res;
        long long n2 = m[target];
        for(auto a : m)
        {
            if(dist(a.second,n2) == K) res.emplace_back(a.first->val);
        }
        return res;

        
    }

    int dist(long n1 , long n2)
    {
        int res = 0;

        while( n1 != n2)
        {
            if(n1>n2) n1 = (n1 - 1) / 2; 
            else  n2 = (n2- 1) / 2;
            ++res; 
        }
        return res;
    }


    void dfs(TreeNode* t, int n)
    {
        if(!t) return ;
        m[t] = n;
        dfs(t->left,2*n+1);
        dfs(t->right,2*n+2);
        return ;
    }
};