// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

//  

// 示例:

// 现有矩阵 matrix 如下：

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// 给定 target = 5，返回 true。

// 给定 target = 20，返回 false。

//  

// 限制：

// 0 <= n <= 1000

// 0 <= m <= 1000

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return false;
        int n = matrix.size(), m = matrix[0].size();
        for( int pos = 0 ; pos < n ;pos ++)
        {
            if(matrix[pos][0] > target || matrix[pos][m-1] < target){}
            else{
                int l = 0, r = m-1;
                int mid = l/2 + r/2;
                while( l < r )
                {
                    mid  = l/2 + r/2;
                    cout << " 1: "<< matrix[pos][mid]  << endl;
                    if( matrix[pos][mid] > target)  r = mid -1;
                    else if( matrix[pos][mid] < target) l = mid +1;
                    else return true;
                }
                mid = l;
                cout << " 2: "<< matrix[pos][l]  << endl;
                if( matrix[pos][mid] == target) return true;
            }
        }
        return false;
    }
};