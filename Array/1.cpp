// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

//  

// 示例:

// 给定 nums = [2, 7, 11, 15], target = 9

// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0 ; i < n -1 ;i++)
        {
            for(int j = i+1 ; j < n;j++)
            {
                if ( nums[i] + nums[j] == target)  return {i,j};
            }
        }

        return {};
    };
};

int main(){
    string input;
    vector<int> nums;
    Solution solution;
    int target;
    int temp = 0 ;

    getline(cin, input , '\n');
	for (int i = input.find('['); i < input.find(']'); ++i)
	{
		if (isdigit(input[i]))  temp =temp* 10 + (input[i] - 48);
	
		if(  (input[i] == ',') ||  (i == (input.find(']') - 1) ) )
		{
			nums.push_back(temp);
			temp = 0;
		}
    }
    target = int(input[ input.length() -1 ]) -48;

    // for( int i = 0 ; i < nums.size();i++) cout << nums[i] << ',' ; 
    // cout << target << endl;
    solution.twoSum(nums,target );
    
    return 0;
}