// 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

// 如果不存在最后一个单词，请返回 0 。

// 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

#include <iostream>
#include <string>


using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {

        int len = 0 ,flag = 0;
        for(int i = s.size()-1; i >= 0 ; i --)
        {
            if(isalpha(s[i])) 
            {
                len++;
                flag = 1 ;
            }
            else if( s[i] == ' ' && flag) return len;
        }

        return len;

    }
};


int main(){
    string s;
    getline(cin,s,'\n');

    Solution so;

    cout  << so.lengthOfLastWord(s) << endl;

    return 0;
}