// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。
// 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。


// 示例1：
// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"

// 示例2：
// 输入: s = "lrloseumgh", k = 6
// 输出: "umghlrlose"


#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) ;
};


string Solution::reverseLeftWords(string s, int n)
{
    string ss(s,n);
    ss+=s.substr(0,n);

    cout << ss << endl;
    return ss;
}


int main()
{
    Solution  solution;
    string input;
    int n ;

    cout << "please input the string and n as the format \"s = \"cdefgab\", n = 2\" " <<endl;
    getline(cin, input, '\n');
    // cout <<input<<endl;
    
    int pos1 = input.find('\"') ;
    int pos2 = input.rfind('\"') ;

    // cout <<pos1 << pos2<<endl;

    string s = input.substr(pos1+1,pos2-pos1-1);
    n = input[input.length()-2] - 30 ;

    solution.reverseLeftWords(s,n);

    return 0;
}