// 给你一个 m x n 的网格 grid。网格里的每个单元都代表一条街道。grid[i][j] 的街道可以是：

// 1 表示连接左单元格和右单元格的街道。
// 2 表示连接上单元格和下单元格的街道。
// 3 表示连接左单元格和下单元格的街道。
// 4 表示连接右单元格和下单元格的街道。
// 5 表示连接左单元格和上单元格的街道。
// 6 表示连接右单元格和上单元格的街道。

// 你最开始从左上角的单元格 (0,0) 开始出发，网格中的「有效路径」是指从左上方的单元格 (0,0) 开始、一直到右下方的 (m-1,n-1) 结束的路径。该路径必须只沿着街道走。

// 注意：你 不能 变更街道。

// 如果网格中存在有效的路径，则返回 true，否则返回 false 。

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map< int , pair<int,int> > m = {{1,make_pair(4,6)}, {2,make_pair(2,8)},{3,make_pair(4,8)}
                                                ,{4,make_pair(6,8)},{5,make_pair(4,2)},{6,make_pair(2,6)}};
    int w = 0;
    int h = 0;
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        w = grid.size();
        h = grid[0].size();
        vector<vector<int>> visit1(w, vector<int>(h, 0));
        vector<vector<int>> visit2(w, vector<int>(h, 0));
        return ( dfs(grid,visit1,0,0,m[grid[0][0]].first) || dfs(grid,visit2,0,0,m[grid[0][0]].second));
    }

    bool dfs(vector<vector<int>>& grid , vector<vector<int>>& visit ,int x, int y,int pos)
    {
        if(x < 0 || x >= w || y < 0 || y >= h ) return false;
        if(visit[x][y] == 1) return false;
        if(pos != m[grid[x][y]].first && pos != m[grid[x][y]].second) return false;

        visit[x][y] = 1;
        pos = (pos == m[grid[x][y]].first)? (m[grid[x][y]].second) : (m[grid[x][y]].first);
        if( (x == (w-1)) && (y == (h-1))) return true;
        
        bool flag=false;
        if(pos == 4) flag |= dfs(grid,visit,x,y-1,6);
        if(pos == 2) flag |= dfs(grid,visit,x-1,y,8);
        if(pos == 6) flag |= dfs(grid,visit,x,y+1,4);
        if(pos == 8) flag |= dfs(grid,visit,x+1,y,2);

        return flag;
    };
};

int main(){

    vector<vector<int>> grid {{4,1,3},{6,1,2}};

    Solution so;

    cout << so.hasValidPath(grid) << endl;

    return 0;
}