// 给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

// 我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，总满足 array[i] <= array[i + 1]。

// 示例 1:

// 输入: nums = [4,2,3]
// 输出: true
// 解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。

// 示例 2:

// 输入: nums = [4,2,1]
// 输出: false
// 解释: 你不能在只改变一个元素的情况下将其变为非递减数列。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        if(nums.size() == 1) return true;

        int count = 0 ; 
        int count2 = 0;
        int pos = 0 ;

        for(int i=0;i< nums.size()-1 ; i++)//size()容器中实际数据个数 
        {
            if(nums[i] > nums[i+1]) 
            {   count++;
                pos = i;
            }
        }

        if(count > 1) return false;
        else
        {
            if(pos == 0 || pos ==nums.size()-2 ) return true;
            else
            {
                if (nums[pos-1] > nums[pos+1]) {
                    nums[pos+1] = nums[pos];
                }else {
                    nums[pos] = nums[pos+1];
                }
                for(int i=0;i< nums.size()-1 ; i++)//size()容器中实际数据个数 
                {
                    if(nums[i] > nums[i+1]) 
                    {   count2++;
                    }
                }
                if(count2 >= 1) return false;
                else return true;

            }
        }
    }
};


int main()
{
    Solution solution;
    vector<int> nums;

    string input;
    cout << "please input the num " << endl;
    getline(cin,input, '\n');


    for(int i = input.find('[');i<= input.find(']');i++ )
    {
        if(input[i] >= '0' && input[i] <= '9') 
        {
            if(input[i-1] == '-')    nums.push_back(-input[i]+48);
            else nums.push_back(input[i]-48);
        }
    }

    // for(int i=0;i<nums.size();i++)//size()容器中实际数据个数 
    // {
    //     cout<<nums[i]<<","<< endl ;
    // }

    cout << solution.checkPossibility(nums) << endl;
    
    return 0;
    }