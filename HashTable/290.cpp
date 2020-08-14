// 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

// 示例1:

// 输入: pattern = "abba", str = "dog cat cat dog"
// 输出: true
// 示例 2:

// 输入:pattern = "abba", str = "dog cat cat fish"
// 输出: false
// 示例 3:

// 输入: pattern = "aaaa", str = "dog cat cat dog"
// 输出: false
// 示例 4:

// 输入: pattern = "abba", str = "dog dog dog dog"
// 输出: false
// 说明:
// 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     bool wordPattern(string pattern, string str) {
//         unordered_map < char , string > m;
//         int pos = 0;
//         int i = 0;
//         for(; i < pattern.size();i++)
//         {
//             if(pos == str.size()) break;

//             if(m.find(pattern[i]) == m.end())
//             {
//                 while(str[pos] != ' ' && pos < str.size())
//                 {
//                     m[pattern[i]] += str[pos];
//                     pos ++;
//                 }
//                 pos ++;

//                 for(auto a:m)
//                 {
//                     if(a.first != pattern[i] && a.second.compare(m[pattern[i]]) == 0 ) return false;
//                 }
//             }
//             else
//             {
//                 int mpos = 0;
//                 while(str[pos] != ' ' && pos < str.size())
//                 {
//                     if (m[pattern[i]][mpos] != str[pos]) return false;
//                     pos ++;
//                     mpos++;
//                 }
//                 pos ++;
//             }
//         }

//         if(pos != str.size()+1 || i != pattern.size() ) return false;
//         return true;
//     }
// };

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        stringstream ss(str); string s;
        for(char c : pattern) {
            if(!(ss >> s) || (map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c)) return false;
            map[c] = s; rmap[s] = c;
        }
        return (ss >> s) ? false : true;
    }
};

int main(){
    Solution so;
    string pattern = "jquery";
    string str = "jquery" ;

    cout << so.wordPattern(pattern, str) << endl;


    return 0;
}
