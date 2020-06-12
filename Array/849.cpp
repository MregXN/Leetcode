// 在一排座位（ seats）中，1 代表有人坐在座位上，0 代表座位上是空的。

// 至少有一个空座位，且至少有一人坐在座位上。

// 亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。

// 返回他到离他最近的人的最大距离。

// 示例 1：

// 输入：[1,0,0,0,1,0,1]
// 输出：2
// 解释：
// 如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
// 如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
// 因此，他到离他最近的人的最大距离是 2 。 
// 示例 2：

// 输入：[1,0,0,0]
// 输出：3
// 解释： 
// 如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
// 这是可能的最大距离，所以答案是 3 。

// 提示：

// 1 <= seats.length <= 20000
// seats 中只含有 0 和 1，至少有一个 0，且至少有一个 1。


#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#define max(a, b)  (((a) > (b)) ? (a) : (b))

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        int left = 0 ;
        int right = 0 ; 
        int last1 = -1 ;
        int distance = 0;
        int n = seats.size();

        for(int i = 0 ; i < n;i++)
        {
            if(seats[i])
            {
                if( last1  == -1)  left = i;
                else if((i - last1) > distance )  distance = i - last1;
                last1 = i;
            }
        }
        right = n-1 - last1;
        distance = floor(distance/2);

        int max = (left > right) ? (left):(right) ; 
        max = (max > distance) ? (max):(distance) ; 

        return max;
    }
};


int main(){
    string input;
    Solution solution;
    vector<int> seats;
    cout << "please input " << endl;

    getline(cin, input ,'\n');
   // cout << input << endl;

    for(int i = input.find('['); i < input.find(']') ;i++ )
    {
        if(input[i] <= '9' && input[i] >= '0' )
        {
            seats.push_back(input[i] - 48);
        }
    }

    //for(int i =0 ; i < seats.size();i++) cout << seats[i];
    cout << solution.maxDistToClosest(seats) << endl;
    return 0 ;
}