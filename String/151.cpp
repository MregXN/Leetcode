// 给定一个字符串，逐个翻转字符串中的每个单词。

//  

// 示例 1：

// 输入: "the sky is blue"
// 输出: "blue is sky the"
// 示例 2：

// 输入: "  hello world!  "
// 输出: "world! hello"
// 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 示例 3：

// 输入: "a good   example"
// 输出: "example good a"
// 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
//  

// 说明：

// 无空格字符构成一个单词。
// 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        vector<string> a;
        string temp = "";

        for(int i = 0 ; i < s.size(); i ++)
        {
            if(s[i] != ' ') 
            {
                temp += s[i];
                if ( i == s.size() -1 ) a.push_back(temp);
            }
            else{
                if(temp.compare("") == 0) continue;
                else{
                    a.push_back(temp);
                    temp = "";
                }
            }    
        }

        string r;
        for(int i = a.size()-1; i >= 0 ; i--) r += a[i] + ((i == 0 ) ? "" : " ");

        return r;
    }
};


int main(){
    string s = "  hello world!  ";
    Solution so;
    cout <<so.reverseWords(s) <<endl;

    return 0;
}