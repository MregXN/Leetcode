// 给你一个 m * n 的矩阵 mat 和一个整数 K ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素 mat[r][c] 的和： 

// i - K <= r <= i + K, j - K <= c <= j + K 
// (r, c) 在矩阵内。
//  

// 示例 1：

// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
// 输出：[[12,21,16],[27,45,33],[24,39,28]]
// 示例 2：

// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
// 输出：[[45,45,45],[45,45,45],[45,45,45]]
//  

// 提示：

// m == mat.length
// n == mat[i].length
// 1 <= m, n, K <= 100
// 1 <= mat[i][j] <= 100

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {

        int m =  mat.size();
        int n =  mat[0].size();

        vector<vector<int>> r(m, vector<int>(n, 0));;

        for( int x = 0 ; x < m ; x ++ )
        {
            for( int y = 0 ; y < n ; y ++ )
            {

                        for( int i = 0 ; i < m ; i ++ )
                        {
                            for( int j = 0 ; j < n ; j ++ )
                            {
                                
                                if( i - K <= x && x  <= i + K && j - K <= y && y <= j + K )
                                {

                                    r[x][y]  += mat[i][j];
                                }
                            }
                        }
            }
        }


        return r;
    }
};