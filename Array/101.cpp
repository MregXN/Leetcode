// 给定一个二叉树，检查它是否是镜像对称的。

//  

// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//  

// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

//     1
//    / \
//   2   2
//    \   \
//    3    3
//  

// 进阶：

// 你可以运用递归和迭代两种方法解决这个问题吗？

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isOmorphism(root->left,root->right);
    }

    bool isOmorphism(TreeNode* node1,TreeNode* node2)
    {
        if( node1 == NULL || node2 == NULL)
        {
            if( (node1 == NULL && node2 == NULL)) return true;
            else return false;
        }

        //cout << node1 -> val <<',' << node2 -> val << endl;

        if(node1 -> val != node2 -> val) return false;
        else return (isOmorphism(node1->left,node2->right) && isOmorphism(node1->right,node2->left));
    };
};


int main(){
    string input;
    vector<int> num;
    Solution solution;
    cout << "please input the num" << endl;

    getline(cin,input,'\n');
    for(int i = 0 ; i < input.size(); i ++) if( input[i] <= '9' && input[i] >= '0')  num.push_back( input[i] - 48 );

    // for(int i = 0 ; i < num.size(); i ++) cout << num[i] << ',';

    TreeNode *a = (TreeNode *)malloc(sizeof(TreeNode) * input.size());
    for(int i = 0 ; i < num.size(); i ++)
    {
        a[i].val =  num[i];

        if(i){
            a[i].left = (2*i+1)<num.size() ? (&a[2*i+1] ) : (NULL);
            a[i].right = (2*i+2)<num.size() ? (&a[2*i+2] ) : (NULL);
        }
        else // root
        {
            a[i].left = (1)<num.size() ? (&a[1] ) : (NULL);
            a[i].right = (2)<num.size() ? (&a[2] ) : (NULL);
        }
    }

    //cout<< a[0].right->left->val << endl;
    cout << solution.isSymmetric(a) << endl;

    return 0;
}