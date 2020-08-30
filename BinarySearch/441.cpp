// 你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。

// 给定一个数字 n，找出可形成完整阶梯行的总行数。

// n 是一个非负整数，并且在32位有符号整型的范围内。

// 示例 1:

// n = 5

// 硬币可排列成以下几行:
// ¤
// ¤ ¤
// ¤ ¤

// 因为第三行不完整，所以返回2.
// 示例 2:

// n = 8

// 硬币可排列成以下几行:
// ¤
// ¤ ¤
// ¤ ¤ ¤
// ¤ ¤

// 因为第四行不完整，所以返回3.
#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        if( n == 0 || n == 1 ) return n;

        int l = 1, r = n, mid;
        while(l <= r)
        {
            mid = (l+r)/2;
            cout << mid << "  "<< l<< " "<< r <<  endl;
            long long ans1  = f(mid);
            long long ans2 = f(mid+1);

            if(ans1 <=n && ans2 >n ) return mid;
            else if( ans1 < n && ans2 <= n) l = mid +1;
            else r = mid -1;
        }
        return mid;
    }

    long long f(int mid){ return(1+mid)*mid/2; }
};


int main(){
    Solution so;


    cout <<  so.arrangeCoins(10)  << endl;


    return 0;
}





