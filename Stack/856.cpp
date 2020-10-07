// 给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：

// () 得 1 分。
// AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
// (A) 得 2 * A 分，其中 A 是平衡括号字符串。
//  

// 示例 1：

// 输入： "()"
// 输出： 1
// 示例 2：

// 输入： "(())"
// 输出： 2
// 示例 3：

// 输入： "()()"
// 输出： 2
// 示例 4：

// 输入： "(()(()))"
// 输出： 6
//  

// 提示：

// S 是平衡括号字符串，且只含有 ( 和 ) 。
// 2 <= S.length <= 50
// 通过次数9,494提交次数15,715
class Solution {
public:
    int scoreOfParentheses(string S) {
        int left_num = 0;
        bool left_update = false;
        int res = 0;

        for(auto& a:S)
        {
            if(a == '(' ) 
            {
                left_num++;
                left_update = true;
            }
            else{
                left_num--;
                if( left_update)
                {
                    res += 1 << left_num;
                    left_update = false;
                }
            }
        }
        return res;
    }
};