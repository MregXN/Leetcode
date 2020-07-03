// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

// 说明：本题中，我们将空字符串定义为有效的回文串。

// 示例 1:

// 输入: "A man, a plan, a canal: Panama"
// 输出: true
// 示例 2:

// 输入: "race a car"
// 输出: false

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();


        for(int pos1=0 , pos2 = n-1; pos1 < n-1 ; pos1++,pos2--)
        {
            while( ! isalpha(s[pos1]) &&! isdigit(s[pos1]) && pos1 < n-1  ) pos1 ++;
            while( ! isalpha(s[pos2]) &&! isdigit(s[pos2]) && pos2 > 0  ) pos2 --;


            if( !isalpha(s[pos1]) && !isalpha(s[pos2]) && !isdigit(s[pos1]) && !isdigit(s[pos2])) return true;
            else if( ((s[pos1]-s[pos2]) != 0) && (toupper(s[pos1])-toupper(s[pos2]) != 0))   return false;


            if( pos2 <= pos1) break;
        }
        return true;
    }
};


int main(){
    string input;
    Solution s;
    getline(cin,input,'\n');

    cout << s.isPalindrome(input) <<endl;

    return 0;
}