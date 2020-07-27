// 给定二叉树，按垂序遍历返回其结点值。

// 对位于 (X, Y) 的每个结点而言，其左右子结点分别位于 (X-1, Y-1) 和 (X+1, Y-1)。

// 把一条垂线从 X = -infinity 移动到 X = +infinity ，每当该垂线与结点接触时，我们按从上到下的顺序报告结点的值（ Y 坐标递减）。

// 如果两个结点位置相同，则首先报告的结点值较小。

// 按 X 坐标顺序返回非空报告的列表。每个报告都有一个结点值列表。

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// private:
//     unordered_map<int,vector<int>> m;
//     vector<vector<int> > r;
//     int size = 0;
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         dfs(root,0);
//         for(int i = -size -1 ; i <=size +1 ;i++)
//         {
//             if(m.find(i) != m.end())
//             {
//                 sort(m[i].begin(),m[i].end());
//                 r.push_back(m[i]);
//             }
//         }
//         return r;
//     }

//     void dfs(TreeNode* root , int balance)
//     {
//         if(root == NULL ) return ;
//         else{
//             if(abs(balance) > size) size = abs(balance);
//             m[balance].push_back(root->val);
//             dfs(root->left,balance-1);
//             dfs(root->right,balance+1);
//         }
//         return;
//     }

// };

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        if(root == NULL) return {{}};
        q.push({root,{0,0}});
        //这里用lft，rgt记录x的取值范围，方便后面构建ans
        int lft=0,rgt=0;
        while(!q.empty()){
            auto tem = q.front().first;
            auto level = q.front().second;
            q.pop();
            lft = min(lft,level.first);
            rgt = max(rgt,level.first);
            mp[{level.first,level.second}].push_back(tem->val);
            if(tem->left != NULL) q.push({tem->left,{level.first-1,level.second+1}});
            if(tem->right!= NULL) q.push({tem->right,{level.first+1,level.second+1}});            
        }
        //加一是有零
        vector<vector<int>> ans(rgt - lft +1);
        for(auto m : mp){
            //对vector排序，直接用set也能过，因为测试用例没有<x,y,val>都相同的情况
            sort(m.second.begin(),m.second.end());
            for(int n : m.second){
                ans[m.first.first-lft].push_back(n);
            }
        }
        return ans;
    }
};

int main(){
    Solution so;



    return 0;
}