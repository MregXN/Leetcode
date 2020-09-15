// 给定一个 N 叉树，找到其最大深度。

// 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

/*
///Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        
        if(!root) return {};
        queue< pair< Node* , int> > q;
        q.push({root,1});
        int ans = 0;

        while(!q.empty())
        {
            Node* cur = q.front().first;
            ans = q.front().second;
            q.pop();

            for(auto a : cur->children)
            {
                q.push(a);
            }
        }

        return ans;

        
    }
};
