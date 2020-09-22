// 对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。

// 格式

// 该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。

// 你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。

// 示例 1:

// 输入: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

//         0
//         |
//         1
//        / \
//       2   3 

// 输出: [1]
// 示例 2:

// 输入: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5 

// 输出: [3, 4]
// 说明:

//  根据树的定义，树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
// 树的高度是指根节点和叶子节点之间最长向下路径上边的数量。

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
private:
    unordered_map<int , vector<int> > m;
    vector<int> res;

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> dis(n,0);
        vector<int> visit(n,0);

        for(auto a : edges)
        {
            m[a[0]].emplace_back(a[1]);
            m[a[1]].emplace_back(a[0]);
        }

        for(int i = 0 ; i < n ; i ++)
        {
            visit = vector<int>(n,0);
            //for(auto c: dis) cout << c <<endl;
            dfs(dis,visit,i,i,0);
            
        }

        int min = INT8_MAX;
        for(int i = 0; i < n ; i++)
        {
            if(dis[i] <= min)
            {
                if(dis[i] != min) res.clear();
                min = dis[i] ;
                res.emplace_back(i);

            }
        }

      //  for(auto c: dis) cout << c <<endl;
        return res;
    }
    
    void dfs(vector<int>& dis,vector<int>& visit,int startpos,int root,int nn)
    {
        if(visit[root]) return;
        visit[root] = 1;
        if(nn > dis[startpos]) dis[startpos] = nn;

        for(auto a: m[root])
        {
            dfs(dis,visit,startpos,a,nn+1);
        }
        return ;
    }


};


int main()
{
    Solution so;
    vector<vector<int>>  v = {{1, 0}, {1, 2}, {1, 3}};
     so.findMinHeightTrees(4 ,v ) ;


    return 0;
}