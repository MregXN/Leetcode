// 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

// 示例 1:

// 输入: nums = [1,2,3,1], k = 3
// 输出: true
// 示例 2:

// 输入: nums = [1,0,1,1], k = 1
// 输出: true
// 示例 3:

// 输入: nums = [1,2,3,1,2,3], k = 2
// 输出: false

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
 public :
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int> map;
        int n = nums.size();

        for (int i = 0 ;  i < n; i ++)
        {
            if( map.find(nums[i]) != map.end() && (i - map[nums[i]] ) <= k  ) return true;
            map[nums[i]] = i;
        }

        return false;
    } ;  
};

int main(){

    string input;
    vector<int> nums;
    int k ;
    Solution solution;


    getline(cin,input,'\n');
    for(int i = input.find('['); i < input.find(']');i++) if(isdigit(input[i])) nums.push_back(input[i]-48) ;
    k = input[input.length()-1] -48;

    // for(int i = 0 ; i < nums.size() ; i ++) cout << nums[i] << ','<<endl;
    // cout << k << endl;

    cout << solution.containsNearbyDuplicate(nums,k) << endl;
    return 0;

}