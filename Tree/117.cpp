// 给定一个二叉树

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

// 初始状态下，所有 next 指针都被设置为 NULL。

//  

// 进阶：

// 你只能使用常量级额外空间。
// 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        queue< pair<Node*,int> > q;
        q.push({root,1});
        while(!q.empty())
        {
            Node* cur = q.front().first;
            int floor = q.front().second;
            q.pop();
            cur->next = (floor == q.front().second ) ? q.front().first : NULL;
            if (cur->left) q.push({cur->left,floor+1});
            if (cur->right) q.push({cur->right,floor+1});
        }

        
        return root;
    }
};
