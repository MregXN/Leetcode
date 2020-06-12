// 假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

// 给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

// 示例 1:

// 输入: flowerbed = [1,0,0,0,1], n = 1
// 输出: True
// 示例 2:

// 输入: flowerbed = [1,0,0,0,1], n = 2
// 输出: False
// 注意:

// 数组内已种好的花不会违反种植规则。
// 输入的数组长度范围为 [1, 20000]。
// n 是非负整数，且不会超过输入数组的大小。




#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        int a= 0;

        if(n > s )  return false;
        else if ( n ==0 ) return true;
        else if ( n == 1 && s ==1 && flowerbed[0] == 0) return true;

        for (int i = 0 ; i < s-1;i ++)
        {
            if(flowerbed[i] == 0 && flowerbed[i+1] == 0)
            {
                if(i == 0 || i+1 == s-1) a++;
                else if( flowerbed[i+2] == 0)
                {
                    a++;
                    i+=1;
                }
                
                if(a >= n) return true;
            }
        }

        return false;
    }
};


int main(){
    string input;
    vector<int> flowerbed;
    int n ;
    Solution solution;

    getline(cin,input , '\n');

    for(int i = input.find('['); i < input.find(']'); i ++)
    {
        if(isdigit(input[i])) flowerbed.push_back(input[i]-48);
    }

    n = input[input.length() -1 ] - 48;

    cout << solution.canPlaceFlowers(flowerbed,n) << endl;

    return 0;
}