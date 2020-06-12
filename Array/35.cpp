// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

// 你可以假设数组中无重复元素。

// 示例 1:
// 输入: [1,3,5,6], 5
// 输出: 2

// 示例 2:
// 输入: [1,3,5,6], 2
// 输出: 1

// 示例 3:
// 输入: [1,3,5,6], 7
// 输出: 4

// 示例 4:
// 输入: [1,3,5,6], 0
// 输出: 0


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int n = nums.size() ; 

        for( int i =0 ; i < n; i ++)
        {
              if (target <= nums[i]) return i;
        }

        return n ;
    }
};



int main()
{
    string input;
    vector<int> nums;
    int target;
    Solution solution;

    cout << " please input the num and the target" << endl;
    getline(cin,input, '\n');

    for (int i = input.find('[') ; i < input.find(']'); i++)
    {
        if( input[i] >= '0' && input[i] <= '9')   nums.push_back(input[i] - 48);
    }

    target = int(input[  input.length() - 1 ]) - 48;

    //for( int i = 0 ; i < nums.size();i++) cout << nums[i] << ',' ;

    cout << solution.searchInsert(nums , target ) << endl;

    return 0;
}