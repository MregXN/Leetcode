// 统计所有小于非负整数 n 的质数的数量。

// 示例:

// 输入: 10
// 输出: 4
// 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

class Solution {
public:
    int countPrimes(int n) {
        bool st[n + 1];
        int primes[n + 1], cnt = 0;
        memset(st, 0, sizeof st);
        for (int i = 2; i < n; i ++)
        {
            if(!st[i]) primes[cnt++] = i;
            for(int j = 0; primes[j] <= n / i; j ++)
            {
                st[primes[j] * i] = true;
                if(i % primes[j] == 0) break;
            }
        }
        return cnt;
    }
};
