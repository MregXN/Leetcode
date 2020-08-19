// 给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。

// 若无答案，则返回空字符串。

//  

// 示例 1：

// 输入：
// words = ["w","wo","wor","worl", "world"]
// 输出："world"
// 解释： 
// 单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
// 示例 2：

// 输入：
// words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// 输出："apple"
// 解释：
// "apply"和"apple"都能由词典中的单词组成。但是"apple"的字典序小于"apply"。
//  

// 提示：

// 所有输入的字符串都只包含小写字母。
// words数组长度范围为[1,1000]。
// words[i]的长度范围为[1,30]。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>



using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> us{words.begin(), words.end()};   
        string res = "";
        for(string &word : words){
            if(word.size() > res.size() || (word.size() == res.size() && word < res)){ 
                bool flag = true;
                for(int i = 1; i < word.size(); ++i){
                    if(!us.count(word.substr(0, i))) {   
                        flag = false;
                        break;
                    }
                }
                if(flag) res = word;
            }
        }
        return res;
    }
};
int main()
{
    Solution so;

    vector<string> words = {"w","wo","wor","worl", "worle", "world"};

    cout << so.longestWord(words) << endl;

    return 0;
}