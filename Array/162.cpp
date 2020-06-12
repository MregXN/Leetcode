// 峰值元素是指其值大于左右相邻值的元素。

// 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

// 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

// 你可以假设 nums[-1] = nums[n] = -∞。

// 示例 1:

// 输入: nums = [1,2,3,1]
// 输出: 2
// 解释: 3 是峰值元素，你的函数应该返回其索引 2。
// 示例 2:

// 输入: nums = [1,2,1,3,5,6,4]
// 输出: 1 或 5 
// 解释: 你的函数可以返回索引 1，其峰值元素为 2；
//      或者返回索引 5， 其峰值元素为 6。
// 说明:

// 你的解法应该是 O(logN) 时间复杂度的。


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n =  nums.size();

        if(n <= 1 ) return 0 ;
        if(nums[0] > nums[1] ) return 0 ;
        if(nums[n -1 ] > nums[n-2]  ) return n-1;

        for(int i = 0 ; i < n-2 ; i++)
        {
            if (nums[i+1] >= nums[i]  && nums[i+1] >= nums[i+2]) return i+1;
        }

        return 0 ;

    }
};



int main(){

    vector<int> nums;
    string input;
    Solution solution;

    getline(cin,input,'\n');

    for(int i = 0 ; i < input.size();i++) if(isdigit(input[i])) nums.push_back(input[i] - '0');

    //for(int i = 0 ; i < nums.size(); i ++) cout << nums[i] << ',' << endl;

    cout << solution.findPeakElement(nums) << endl;
    return 0 ;
}