// 给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 

// 请你统计并返回 grid 中 负数 的数目。

//  

// 示例 1：

// 输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// 输出：8
// 解释：矩阵中共有 8 个负数。
// 示例 2：

// 输入：grid = [[3,2],[1,0]]
// 输出：0
// 示例 3：

// 输入：grid = [[1,-1],[-1,-1]]
// 输出：3
// 示例 4：

// 输入：grid = [[-1]]
// 输出：1
//  

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// -100 <= grid[i][j] <= 100
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int mid = grid[0].size()-1;
        for ( auto a:grid)
        {
            mid = find(a,0,mid);
            if(mid == -1) break;
            res+= (mid == grid[0].size())? ((mid--),0) : grid[0].size()-mid;
        }

        return res;
    }


    int find(vector<int> v, int left,int right)
    {
        if(v[left] < 0)  return left;
        if(v[right] >= 0)  return v.size();
        if(left > right) return -1;

        int mid = (left+right)/2;
        if(mid == 0 ) return (v[right]<0)?right:-1;
        if(v[mid] <0 && v[mid-1] >= 0 ) return mid;
        if(v[mid] <0 && v[mid-1] < 0 ) return find(v,left,mid-1);
        if(v[mid] >=0 && v[mid-1] >= 0 ) return find(v,mid+1,right);

        return 0;
    }
};

int main(){
    Solution so;
    vector<vector<int>> grid = {{4,3,3,1,1},{1,0,0,-1,-1},{-2,-2,-2,-2,-3},{-2,-2,-2,-3,-3},{-3,-3,-3,-3,-3}};

    cout << so.countNegatives(grid)<<endl;
    return 0;
}