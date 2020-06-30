// 在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。

// 给出一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。

// 返回可以通过分割得到的平衡字符串的最大数量。

//  

// 示例 1：

// 输入：s = "RLRRLLRLRL"
// 输出：4
// 解释：s 可以分割为 "RL", "RRLL", "RL", "RL", 每个子字符串中都包含相同数量的 'L' 和 'R'。
// 示例 2：

// 输入：s = "RLLLLRRRLR"
// 输出：3
// 解释：s 可以分割为 "RL", "LLLRRR", "LR", 每个子字符串中都包含相同数量的 'L' 和 'R'。
// 示例 3：

// 输入：s = "LLLLRRRR"
// 输出：1
// 解释：s 只能保持原样 "LLLLRRRR".
//  

// 提示：

// 1 <= s.length <= 1000
// s[i] = 'L' 或 'R'
// 分割得到的每个字符串都必须是平衡字符串。


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int numL =0,numR = 0;
            //当L和R出现的数量一致时 表示可以平分
        for(int i = 0;i<s.size();i++){
            if(s[i]=='L') numL++;
            if(s[i]=='R') numR++;
            if(numL==numR) res++;
        }
        return res;
    }
};




int main(){
    string input,s ;
    Solution S;

    getline(cin,input,'\n');

    for(auto c : input) {
        if( c == 'R' || c == 'L') s += c;
    }

    cout << s<<endl;

    cout << S.balancedStringSplit(s)<< endl;

    return 0;
}