// 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

// 假定 BST 有如下定义：

// 结点左子树中所含结点的值小于等于当前结点的值
// 结点右子树中所含结点的值大于等于当前结点的值
// 左子树和右子树都是二叉搜索树
// 例如：
// 给定 BST [1,null,2,2],

//    1
//     \
//      2
//     /
//    2
// 返回[2].

// 提示：如果众数超过1个，不需考虑输出顺序

// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution 
{
public:
    vector<int> findMode(TreeNode* root) 
    {
        unordered_map<int,int> map;
        vector<int> result;
        int max = 0;
        map_fill(root,map);

        for ( auto p = map.begin(); p != map.end(); ++p )
        {
            if(p->second >= max){
                if(p->second > max ) result.clear();
                max = p->second;
                result.push_back(p->first);
            }
        }
        return result;

    }

    void map_fill(TreeNode* root,unordered_map<int,int>& map )
    {
        if(root == NULL) return ;
        else{
            map[root->val] ++;
            map_fill(root->left,map);
            map_fill(root->right,map);
        }
        return;
    }
};