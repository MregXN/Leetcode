// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

// 你可以假设除了整数 0 之外，这个整数不会以零开头。

// 示例 1:

// 输入: [1,2,3]
// 输出: [1,2,4]
// 解释: 输入数组表示数字 123。
// 示例 2:

// 输入: [4,3,2,1]
// 输出: [4,3,2,2]
// 解释: 输入数组表示数字 4321。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n =  digits.size();

        digits[n-1] ++;
        for (int i = n-1 ; i >=0 ; i --) 
        {
            if(digits[i]== 10 )  
            {   
                digits[i] = 0;
                if(i)   digits[i-1] ++ ;
                else digits.insert(digits.begin(),1);
            }
        }  

        return digits;
    }
};

int main(){
    string input;
    vector<int> digits;
    Solution solution;
     
    cout << "please input the num" << endl;
    getline(cin,input, '\n');

    for(int i = input.find('[') ; i < input.find(']') ; i++ )
    {
        if(input[i] >= '0' && input[i] <= '9' )  digits.push_back(input[i] - 48 );
    }


    solution.plusOne(digits);

}


