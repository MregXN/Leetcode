class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return{};
        vector<vector<int>> res;
        queue<Node*> q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i = 0 ; i < size ; i ++)
            {
                Node* cur = q.front();
                q.pop();
                temp.emplace_back(cur->val);
                for(auto c : cur->children)  if(c) q.push(c);
            }

            res.emplace_back(temp);  //emplace_back 比 pushback效率更高
        }

        return res;
    }
};