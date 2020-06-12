// 在老式手机上，用户通过数字键盘输入，手机将提供与这些数字相匹配的单词列表。每个数字映射到0至4个字母。给定一个数字序列，实现一个算法来返回匹配单词的列表。你会得到一张含有有效单词的列表。映射如下图所示：

// 示例 1:

// 输入: num = "8733", words = ["tree", "used"]
// 输出: ["tree", "used"]
// 示例 2:

// 输入: num = "2", words = ["a", "b", "c", "d"]
// 输出: ["a", "b", "c"]
// 提示：

// num.length <= 1000
// words.length <= 500
// words[i].length == num.length
// num中不会出现 0, 1 这两个数字

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:

    unordered_map<char,string> keyboard;
    vector<string> result;

    void keyboard_load(){
        keyboard['2'] = "abc";
        keyboard['3'] = "def";
        keyboard['4'] = "ghi";
        keyboard['5'] = "jkl";
        keyboard['6'] = "mno";
        keyboard['7'] = "pqrs";
        keyboard['8'] = "tuv";
        keyboard['9'] = "wxyz";
    };

    vector<string> getValidT9Words(string num, vector<string>& words) {

        int wsize = words.size();
        int nsize = num.size();

        keyboard_load();

        for(int i = 0 ; i < wsize ; i ++)
        {
            int wordssize = words[i].size();
            
            if( wordssize != nsize ) continue;
            else
            {
                for(int j = 0 ; j < wordssize ; j ++)
                {
                    if( keyboard[num[j]].find( words[i][j]) == string::npos ) break;
                    else if ( j == wordssize -1 ) result.push_back(words[i]);
                }
            }
        }

        return result;
    };
};

int main(){
    bool flag = false;
    string num , input,temp;
    vector<string> words;
    Solution solution;

    getline(cin,input,'\n');

    for(int i = input.find('\"') ; i < input.find(','); i ++  )
    {
       if( isdigit(input[i]) ) num += input[i];
    }
    
    for(int i = input.find('[') ; i < input.find(']'); i ++  )
    {
        if(input[i] == '\"')  
        {
            if(!flag) temp = "";
            else words.push_back(temp);

            flag = ! flag;
        }
        else temp += input[i];
    }

    // cout << num  << endl;

    // for(int i = 0 ; i <words.size();i++) cout << words[i] << endl;

    solution.getValidT9Words(num,words);

    return 0;
}