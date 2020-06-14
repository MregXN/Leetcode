// 给定一个整数数组，找出总和最大的连续数列，并返回总和。

// 示例：

// 输入： [-2,1,-3,4,-1,2,1,-5,4]
// 输出： 6
// 解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 进阶：

// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        int result = 0 ;

        if(n == 1) return nums[0]; 

        for(int i = 0; i < n ;i ++ )
        {
            if(nums[i] < -sum ) {
                sum = 0 ;
                continue;
            }

            sum += nums[i];
            if(sum  > result) result = sum;
        }

        return result;

    }
};


int main(){
    string input;
    vector<int> nums;    
    
    getline(cin, input , '\n');
    for(int i  =  0 ; i < input.size();i++)  
    {
        if (isdigit(input[i]))  {
            if(input[i-1] == '-')  nums.push_back(- input[i] + '0');
            else nums.push_back(input[i] - '0');
        }
    }
    //for(int i = 0 ; i < nums.size(); i ++)  cout << nums[i] << endl;

    Solution solution;

    cout << solution.maxSubArray(nums) <<endl;
    return 0 ;
    }