// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

//  

// 示例：

// s = "leetcode"
// 返回 0

// s = "loveleetcode"
// 返回 2
//  

// 提示：你可以假定该字符串只包含小写字母。


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<s.size();i++){
            if(s.find(s[i])==s.rfind(s[i]))
            return i;
        }
        return -1;
    }
};



int main(){
    string input,s;


    getline(cin,input,'\n');


    for(int i = input.find('\"') +1 ; i< input.rfind('\"') ; i ++ ) s+= input[i];



    Solution so;

    cout << so.firstUniqChar(s) << endl;

    return 0;
}