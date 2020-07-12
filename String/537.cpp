// 给定两个表示复数的字符串。

// 返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。

// 示例 1:

// 输入: "1+1i", "1+1i"
// 输出: "0+2i"
// 解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
// 示例 2:

// 输入: "1+-1i", "1+-1i"
// 输出: "0+-2i"
// 解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
// 注意:

// 输入字符串不包含额外的空格。
// 输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。
// 通过次数6,424提交次数9,219

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {

        int aa[2],bb[2],result[2];
        int temp = 0;
        bool minus = false;
        for(auto c: a)
        {
            if (c == '-') minus = true;
            else if(isdigit(c)) temp = temp*10 + c - '0';
            else if( c == '+') 
            {   
                aa[0] = minus ? -temp : temp;
                temp = 0;
                minus = false;
            }
            else if ( c == 'i')
            {   
                aa[1] = minus ? -temp : temp;
                temp = 0;
                minus = false;
            }
        }

        for(auto c: b)
        {
            if (c == '-') minus = true;
            else if(isdigit(c)) temp = temp*10 + c - '0';
            else if( c == '+') 
            {   
                bb[0] = minus ? -temp : temp;
                temp = 0;
                minus = false;
            }
            else if ( c == 'i')
            {   
                bb[1] = minus ? -temp : temp;
                temp = 0;
                minus = false;
            }
        }

        result[0] = aa[0]*bb[0] - aa[1]*bb[1];
        result[1] = aa[1]*bb[0] + aa[0]*bb[1];


        return to_string(result[0]) + '+' + to_string(result[1]) + 'i';

    }
};


int main(){
    string a = "78+-76i" , b ="78+-76i"
"-86+72i";

    Solution so;


    cout << so.complexNumberMultiply(a , b) << endl;
    return 0;
}



