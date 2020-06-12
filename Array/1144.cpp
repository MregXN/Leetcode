// 给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。

// 如果符合下列情况之一，则数组 A 就是 锯齿数组：

// 每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
// 或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
// 返回将数组 nums 转换为锯齿数组所需的最小操作次数。

//  

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：2
// 解释：我们可以把 2 递减到 0，或把 3 递减到 1。
// 示例 2：

// 输入：nums = [9,6,1,6,2]
// 输出：4
//  

// 提示：

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {

        int n = nums.size();
        vector<int> tmp(nums);
        int count1 =  0;
        int count2 = 0;

        for(int i = 0 ; i < n ; i += 2) // 偶数检测
        {
            if(i-1 >= 0 && nums[i-1] >= nums[i]  )
            {
                count1 += nums[i-1] - nums[i] +1;
                nums[i-1] = nums[i] -1 ;
            }    

            if(i+1 <= n-1 && nums[i+1] >= nums[i]  )
            {
                count1 += nums[i+1] - nums[i] +1;
                nums[i+1] = nums[i] -1 ;
            }  
        }

        for(int i = 1 ; i < n ; i += 2) //奇数检测
        {
            if( (i-1 >= 0 )&& tmp[i-1] >= tmp[i]  )
            {
                count2 += tmp[i-1] - tmp[i] +1;
                tmp[i-1] = tmp[i] -1 ;
            }    

            if( (i+1 <= n-1 )&& tmp[i+1] >= tmp[i]  )
            {
                count2 += tmp[i+1] - tmp[i] +1;
                tmp[i+1] = tmp[i] -1 ;
            } 
        }
        return (count1 >= count2) ?  count2 : count1;
    };
};


int main (){
    string input;
    vector<int> nums;
    Solution solution;

    getline(cin,input,'\n');
    for(int i = input.find('[') ; i < input.find(']');i++) if(isdigit(input[i])) nums.push_back(input[i] - 48);

    //for(int i = 0 ; i < nums.size(); i ++) cout << nums[i] << ',' << endl;
    cout << solution.movesToMakeZigzag(nums) << endl;
    return 0;
}