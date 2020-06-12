// 设计一个算法，判断玩家是否赢了井字游戏。输入是一个 N x N 的数组棋盘，由字符" "，"X"和"O"组成，其中字符" "代表一个空位。

// 以下是井字游戏的规则：

// 玩家轮流将字符放入空位（" "）中。
// 第一个玩家总是放字符"O"，且第二个玩家总是放字符"X"。
// "X"和"O"只允许放置在空位中，不允许对已放有字符的位置进行填充。
// 当有N个相同（且非空）的字符填充任何行、列或对角线时，游戏结束，对应该字符的玩家获胜。
// 当所有位置非空时，也算为游戏结束。
// 如果游戏结束，玩家不允许再放置字符。
// 如果游戏存在获胜者，就返回该游戏的获胜者使用的字符（"X"或"O"）；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    string result;

    string  toresult(const  char * s ){
        result = s;
        return result;

    };

    string toresult(char s)
    {
        result = s;
        return result;
    }

    string toresult(string s)
    {
        result = s;
        return result;
    }

    string tictactoe(vector<string>& board) {
        int N = board.size();
        int blank_flag = 0;

        if( N  == 1) return (board[0] == " ") ? toresult("Pending"):toresult(board[0]);

        for(int i = 0 ; i < N ; i ++)  //行检测
        {
            if(!blank_flag && board[i].find(' ') != string::npos) blank_flag = 1 ;

            for(int j = 0 ; j < N ; j ++)
            {
                if( board[i][j] != board[i][0] ||  board[i][0] == ' ') break;
                else if( j == N-1 )  return toresult(board[i][0]);
            }
        }

        for(int i = 0 ; i < N ; i ++)  // 列检测
        {
            for(int j = 0 ; j < N ; j ++)
            {
                if( board[j][i] != board[0][i] ||  board[0][i] == ' ') break;
                else if( j == N-1 )  return toresult(board[0][i]);
            }
        }

        for(int i = 0 ; i < N ; i ++)  //对角线1检测
        {
            if( board[i][i] != board[0][0] ||  board[0][0] == ' ') break;
            else if( i == N-1 )  return toresult(board[0][0]);
        }

        for(int i = 0 ; i < N ; i ++)  //对角线2检测
        {
            if( board[i][N-1-i] != board[0][N-1] ||  board[0][N-1] == ' ') break;
            else if( i == N-1 )  return toresult(board[0][N-1]);
        }

        return blank_flag ? toresult("Pending"):toresult("Draw");
    }
};

int main(){
    string s;
    string input;
    vector<string> board;    
    Solution solution;

    int count =0;

    getline(cin,input,'\n');

    for(int i = input.find('[') ; i <= input.find(']') ; i++ )
    {
        if(input[i] == 'O' || input[i] == 'X' || input[i] == ' ' ) s += input[i];
        else if (input[i] == '\"' )
        {
            count ++ ;

            if(count %2 == 1) s = "";
            else board.push_back(s);
        }
    } 

    //for(int i = 0 ; i <= board.size();i++) cout << board[i] << ',' << endl;

    cout << solution.tictactoe(board) << endl;

}