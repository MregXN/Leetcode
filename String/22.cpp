// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

//  

// 示例：

// 输入：n = 3
// 输出：[
//        "((()))",
//        "(()())",
//        "(())()",
//        "()(())",
//        "()()()"
//      ]

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int n = 0;
public:
    vector<string> generateParenthesis(int N) {
        n = N;
        vector<string> result;
        generateAll(string( 2*n, '\0'),0,result);
        return result;

    };

    void generateAll(string current , int pos , vector<string>& result)
    {
        if(pos == 2*n){
            if(valid(current)) 
            {
                result.push_back(current);
            }
        }
        else{
            current[pos] = '(';
            generateAll(current , pos+1,result);
            current[pos] = ')';
            generateAll(current , pos+1,result);
        }
    };

    bool valid(string current)
    {
        int balance = 0 ;
        for(char c : current)
        {
            if( c == '(' ) balance ++;
            else if(  c == ')') balance --;
            if(balance < 0 ) return false; 
        }
        return (balance == 0);
    };

};


int main(){

    int n;
    string input;
    Solution   s;
    getline(cin,input,'\n');

    for(auto c : input) if(isdigit(c)) n = c-'0';

    s.generateParenthesis(n);

    return 0;
}