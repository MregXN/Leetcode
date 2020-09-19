// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

//  

// 示例 1:

// 输入:
// [
// ['1','1','1','1','0'],
// ['1','1','0','1','0'],
// ['1','1','0','0','0'],
// ['0','0','0','0','0']
// ]
// 输出: 1
// 示例 2:

// 输入:
// [
// ['1','1','0','0','0'],
// ['1','1','0','0','0'],
// ['0','0','1','0','0'],
// ['0','0','0','1','1']
// ]
// 输出: 3
// 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。


class Solution {
private:
    int islandNo = 1;
    int n;
    int m;
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if(!n) return 0;
        m = grid[0].size();
        if(!m) return 0;

        for(int i = 0 ; i < n;i++)
        {
            for(int j = 0 ; j < m;j++)
            {
                if( grid[i][j] == '1' )
                {
                    islandNo++;
                    modify(i,j,grid);
                }
            }
        }

        return islandNo-1;

    }


    void modify(int x,int y,vector<vector<char>>& grid)
    {
        queue<pair< int, int >> q;
        pair<int , int > pos;
        q.push({x,y});
        while(!q.empty())
        {
            pos = q.front();
            q.pop();

            if( pos.first<0 || pos.first >=n || pos.second<0 || pos.second >=m || grid[pos.first][pos.second] != '1' ) continue ;
            grid[pos.first][pos.second] =  islandNo;

            q.push({pos.first-1,pos.second});
            q.push({pos.first+1,pos.second});
            q.push({pos.first,pos.second-1});
            q.push({pos.first,pos.second+1});
        }
    }

};