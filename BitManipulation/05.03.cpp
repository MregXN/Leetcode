// 给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。

// 示例 1：

// 输入: num = 1775(110111011112)
// 输出: 8
// 示例 2：

// 输入: num = 7(01112)
// 输出: 4

class Solution {
public:
    int reverseBits(int num) {
        unsigned int NUM = (unsigned int)num;
        int zero_pos1 = -1 , zero_pos2 = -1;
        int res=0;
        for(int i = 0 ; i <33; i++)
        {
            if(!(NUM&1))
            {
                res = max(i -zero_pos1-1 ,res );
                zero_pos1 = zero_pos2;
                zero_pos2 = i;
            }
            NUM>>=1;
        }
        return res;
    }
};