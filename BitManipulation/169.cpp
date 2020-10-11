// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

//  

// 示例 1:

// 输入: [3,2,3]
// 输出: 3
// 示例 2:

// 输入: [2,2,1,1,1,2,2]
// 输出: 2
// 通过次数222,157提交次数343,029
// 

排序

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];               //因为出现频率大于n/2，所以排序后的中间位置必然是众数
    }
};
哈希

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(int n:nums)   
            if(++ mp[n] > nums.size()/2)   return n;         
        return -1;
    }
};
Moore投票

class Solution {
public:
    int majorityElement(vector<int>& nums) {    //摩尔投票法，投我++，不投--，超过一半以上的人投我，那我稳赢哇
        int count=0,candidate;
        for(int n:nums)
        {
            if(count==0)        candidate=n;

            if(n==candidate)    count++;
            else                count--;
        }
        return candidate;
    }
};
随机数

class Solution {
public:
    int majorityElement(vector<int>& nums) {    //每一轮随机选择一个数字，统计出现次数，因为目标出现频率大于二分之一，所以效率较高
        while(true)
        {
            int candidate=nums[rand() % nums.size()],count=0;   
            for(int n:nums)
            {
            if(n==candidate)     
                count++;
            }
            if(count > nums.size()/2)           return candidate;
        }
        return -1;
    }
};
位运算

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int res=0;
    for(int i=0;i<32;i++)
    {
        int ones=0;
        for(int n:nums)
            ones += (n >> i) & 1;                        //位运算法统计每个位置上1出现的次数，每次出现则ones+1
        res += (ones > nums.size()/2) << i;              //如果1出现次数大于2分之1数组的长度，1即为这个位置的目标数字
    }
    return res;
}
};


