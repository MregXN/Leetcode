// 两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

// 计算一个数组中，任意两个数之间汉明距离的总和。

// 示例:

// 输入: 4, 14, 2

// 输出: 6

// 解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
// 所以答案为：
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
// 注意:

// 数组中元素的范围为从 0到 10^9。
// 数组的长度不超过 10^4。


class Solution {
public:
int totalHammingDistance(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    int ans = 0, n = nums.size();
    vector<int> cnt(32, 0);         // count of elements with a particular bit ON

    for (auto num : nums) {         // loop over every element
        int i = 0;
        while (num > 0) {           // check every bit
            cnt[i] += (num & 0x1);
            num >>= 1;
            i++;
        }
    }

    for (auto&& k : cnt) {           // loop over every bit count
        ans += k * (n - k);
    }

    return ans;
}
};