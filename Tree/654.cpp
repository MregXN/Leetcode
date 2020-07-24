// 给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

// 二叉树的根是数组中的最大元素。
// 左子树是通过数组中最大值左边部分构造出的最大二叉树。
// 右子树是通过数组中最大值右边部分构造出的最大二叉树。
// 通过给定的数组构建最大二叉树，并且输出这个树的根节点。

//  

// 示例 ：

// 输入：[3,2,1,6,0,5]
// 输出：返回下面这棵树的根节点：

//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1
//  

// 提示：

// 给定的数组的大小在 [1, 1000] 之间。

#include<iostream>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left ;
     TreeNode *right ;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        int maxpos = findmax(0,nums.size()-1 , nums);
        TreeNode *root = new TreeNode(nums[maxpos]);
        construct(0,nums.size()-1,nums,root,maxpos);
        return root;

    }

    void construct(int left , int right , vector<int>& nums , TreeNode* root,int maxpos)
    {
        root->val = nums[maxpos];
        int leftmaxpos = findmax(left,maxpos-1,nums);
        if(leftmaxpos != -1){
            TreeNode* temp1 = new TreeNode(0);
            root->left = temp1;
            construct(left,maxpos-1,nums,temp1,leftmaxpos);
        }

        int rightmaxpos = findmax(maxpos+1,right,nums);
        if(rightmaxpos != -1){
            TreeNode* temp2= new TreeNode(0);
            root->right = temp2;
            construct(maxpos+1,right,nums,temp2,rightmaxpos);
        }

    }

    int findmax(int left,int right,vector<int>& nums)
    {
        if(left > right) return -1;
        else
        {
            int maxnum = nums[left],pos = left;
            for(int i = left; i <=right;i++) 
            {
                if(nums[i] > maxnum)
                {
                    maxnum = nums[i];
                    pos = i;
                }
            }
            return pos;
        }
    }

};


// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         return makeTree(nums,0,nums.size() - 1);
//     }
//     TreeNode* makeTree(vector<int>& nums,int left,int right)
//     {   
//         if(left > right)
//             return nullptr;

//         int maxIndex = left,max = INT_MIN;
//         for(int i = left; i <= right; ++i)
//             if(nums[i] > max)
//             {
//                 max = nums[i];
//                 maxIndex = i;
//             }    
//         TreeNode* Node = new TreeNode(nums[maxIndex]);
//         Node->left = makeTree(nums,left,maxIndex-1);
//         Node->right = makeTree(nums,maxIndex+1,right);
//         return Node;
//     }
// };



int main() {
    vector<int> nums = {3,2,1,6,0,5};
    Solution so;


    so.constructMaximumBinaryTree(nums);    
    
    


}