// 机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：

// -2：向左转 90 度
// -1：向右转 90 度
// 1 <= x <= 9：向前移动 x 个单位长度
// 在网格上有一些格子被视为障碍物。

// 第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])

// 机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。

// 返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。

//  

// 示例 1：

// 输入: commands = [4,-1,3], obstacles = []
// 输出: 25
// 解释: 机器人将会到达 (3, 4)
// 示例 2：

// 输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
// 输出: 65
// 解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
//  

// 提示：

// 0 <= commands.length <= 10000
// 0 <= obstacles.length <= 10000
// -30000 <= obstacle[i][0] <= 30000
// -30000 <= obstacle[i][1] <= 30000
// 答案保证小于 2 ^ 31

class Solution {
private:
    int direction = 1; // 1 north  2 west 3 south 4 east
    vector<int> pos = {0,0};

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for(auto c :commands) 
        {
            cmd(c,obstacles);
            cout << pos[0] << "," << pos[1] << endl;
        }
        return pow(pos[0],2) + pow(pos[1],2);

    }

    void cmd(int cmd , vector<vector<int>>& obstacles)
    {
        switch(cmd)
        {
            case -2 :
                direction =  (direction == 1)?4: direction - 1 ;
                break;
            
            case -1:
                direction =  (direction == 4)?1: direction + 1 ;
                break;

            default:
                move(cmd,obstacles);
                break;
        }    
    }


    void move(int length, vector<vector<int>>& obstacles)
    {
        int xmove = 0 , ymove = 0;


        if(obstacles.size() == 0)
        {
            switch(direction)
            {
                case  1:
                    ymove = length;
                break;

                case  2:
                    xmove  = length;
                break;

                case  3:
                    ymove = -length;
                break;

                case  4:
                    xmove = -length;
                break;

                default:
                break;
            }

        }
        else
        {
            for(auto o:obstacles)
            {
                switch(direction)
                {
                    case  1:
                        if(o[0] == pos[0] && o[1]-pos[1] <= length) ymove = o[1]-pos[1]-1;
                        else ymove = length;
                    break;

                    case  2:
                        if(o[1] == pos[1] && o[0]-pos[0] <= length) xmove = o[0]-pos[0] -1;
                        else xmove  = length;
                    break;

                    case  3:
                        if(o[0] == pos[0] && pos[1] - o[1] <= length) ymove = o[1]-pos[1]+1;
                        else ymove = - length;
                    break;

                    case  4:
                        if(o[1] == pos[1] && pos[0]-o[0] <= length) xmove = o[0]-pos[0] -1;
                        else xmove = -length;
                    break;

                    default:
                    break;
                }
            }
        }
        

        pos[0] += xmove;
        pos[1] += ymove;
    }
};


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int ans = 0;
        unordered_map<int, unordered_set<int>> ob;
        for (auto& p : obstacles)
        {
            ob[p[0]].insert(p[1]);
        }

        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int dir = 0;
        vector<int> pos = { 0,0 };

        for (auto& c : commands)
        {
            dir = (c == -2) ? (dir + 4 - 1) % 4 : dir;
            dir = (c == -1) ? (dir + 1) % 4 : dir;
            for (int i = 0; i < c; i++)
            {
                vector<int> next = { pos[0] + dd[dir][0], pos[1] + dd[dir][1] };
                if (ob[next[0]].count(next[1]) != 0) break;
                pos = next;
                ans = max(ans, pos[0] * pos[0] + pos[1] * pos[1]);
            }
        }

        return ans;
    }

};