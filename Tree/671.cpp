// 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。

// 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

// 示例 1:

// 输入: 
//     2
//    / \
//   2   5
//      / \
//     5   7

// 输出: 5
// 说明: 最小的值是 2 ，第二小的值是 5 。
// 示例 2:

// 输入: 
//     2
//    / \
//   2   2

// 输出: -1
// 说明: 最小的值是 2, 但是不存在第二小的值。
#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL)  return -1;
        else
        {
            int r = dfs(root,root->val,0x7fffffff);
            return (r == 0x7fffffff  && !flag) ?  -1 : r;
        }
        return -1;
    }

    int dfs(TreeNode* root,int MIN, int min2)
    {
        if(root == NULL) return min2;
        else
        {
            int new_min2 = (root->val > MIN && root->val <= min2) ? (flag = true,root->val) :  min2;
            return min( dfs(root->left,MIN,new_min2), dfs(root->right,MIN,new_min2));
        }
        return min2;
    }
private:
bool flag = false;
};

