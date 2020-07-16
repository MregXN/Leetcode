// 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

// 注意：两个节点之间的路径长度由它们之间的边数表示。

// 示例 1:

// 输入:

//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
// 输出:

// 2
// 示例 2:

// 输入:

//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
// 输出:

// 2

#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 
class Solution {
public:
    int help(TreeNode* node, int &ans) {
        if (node == nullptr) return 0;

        int left = help(node->left, ans);
        int right = help(node->right, ans);

        left = (node->left != nullptr && node->val == node->left->val) ? left + 1 : 0;
        right = (node->right != nullptr && node->val == node->right->val) ? right + 1 : 0;

        ans = max(ans, left + right);
        return max(left, right);
    }

    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        help(root, ans);
        return ans;
    }

};

int main(){
    Solution so;
    vector<TreeNode> T;
    string input;
    
    getline(cin,input , '\n');
    
    for(auto c : input) 
        if(isdigit(c))
            T.push_back(TreeNode(c-'0'));

    for(int i = 0 ; i < T.size();i++ ) 
    {
        T[i].left = (2*i+1 >= T.size()) ?  NULL : &T[2*i+1];
        T[i].right = (2*i+2 >= T.size()) ?  NULL : &T[2*i+2];
    }

    cout << so.longestUnivaluePath(&T[0]) << endl;

    return 0;
}