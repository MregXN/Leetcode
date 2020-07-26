// 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

// 说明: 叶子节点是指没有子节点的节点。

// 示例:
// 给定如下二叉树，以及目标和 sum = 22，

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// 返回:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

class Solution {
private:
    vector<vector<int>> result; 
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        dfs(root,0,sum,path);
        return result;
    }


    void dfs(TreeNode* root, int sum,int target,vector<int> path )
    {
        if(!root) return ;
        else{
            sum += root->val;
            path.push_back(root->val);
            if( !root->left && !root->right )
            {
                if(sum == target)  result.push_back(path);
            }   
            else{
                dfs(root->left,sum,target,path);
                dfs(root->right,sum,target,path);
            }
        }
        return;
    }


};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;//防止反复初始化数组 
    void dfs(TreeNode* root,int sum){
        int resum=sum-root->val;
        temp.push_back(root->val);
        if(resum==0&&!root->left&&!root->right)
			res.push_back(temp);//找到答案 
        if(root->left)
			dfs(root->left,resum);
        if(root->right)
			dfs(root->right,resum);
        temp.pop_back();//回溯 
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root)dfs(root,sum);
        return res;
    }
};
