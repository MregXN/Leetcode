// 编写函数，实现许多图片编辑软件都支持的「颜色填充」功能。

// 待填充的图像用二维数组 image 表示，元素为初始颜色值。初始坐标点的横坐标为 sr 纵坐标为 sc。需要填充的新颜色为 newColor 。

// 「周围区域」是指颜色相同且在上、下、左、右四个方向上存在相连情况的若干元素。

// 请用新颜色填充初始坐标点的周围区域，并返回填充后的图像。

//  

// 示例：

// 输入：
// image = [[1,1,1],[1,1,0],[1,0,1]] 
// sr = 1, sc = 1, newColor = 2
// 输出：[[2,2,2],[2,2,0],[2,0,1]]
// 解释: 
// 初始坐标点位于图像的正中间，坐标 (sr,sc)=(1,1) 。
// 初始坐标点周围区域上所有符合条件的像素点的颜色都被更改成 2 。
// 注意，右下角的像素没有更改为 2 ，因为它不属于初始坐标点的周围区域。
//  

// 提示：

// image 和 image[0] 的长度均在范围 [1, 50] 内。
// 初始坐标点 (sr,sc) 满足 0 <= sr < image.length 和 0 <= sc < image[0].length 。
// image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535] 内。


class Solution {
private:
    int row = 0;
    int cloumn  = 0;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        row = image.size();
        cloumn = image[0].size();
        vector<vector<int>> v(row,vector<int>(cloumn));

        dfs(v,image,sr,sc,newColor,image[sr][sc] );
        return image;

    }

    void dfs(vector<vector<int>>& v,vector<vector<int>>& image,int rpos , int cpos , int newColor,int srcColor)
    {
        if(rpos < 0 || rpos >= row || cpos < 0 || cpos >= cloumn) return;
        if(v[rpos][cpos] == 1 ) return;
        if(image[rpos][cpos] != srcColor) return;

        image[rpos][cpos] = newColor;
        v[rpos][cpos] = 1 ;
        
        dfs(v,image,rpos+1,cpos,newColor,srcColor);
        dfs(v,image,rpos,cpos+1,newColor,srcColor);
        dfs(v,image,rpos-1,cpos,newColor,srcColor);
        dfs(v,image,rpos,cpos-1,newColor,srcColor);
        return ;
    }
};


