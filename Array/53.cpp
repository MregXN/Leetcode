// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

//  

// 示例 1:

// 输入: [0,1,3]
// 输出: 2

// 示例 2:
// 输入: [0,1,2,3,4,5,6,7,9]
// 输出: 8
//  

// 限制：

// 1 <= 数组长度 <= 10000

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    int n;

    int missingNumber(vector<int>& nums) {
        n = nums.size();
        //return find( nums , n/2);

        for(int i = 0 ; i < n;i++){

            if(nums[i] != i ) return i;
        }

        return n;
    }


    int find (vector<int>& nums , int pos ){

        if(nums[pos] == pos)   return (pos == n-1) ? n : ((nums[pos+1] == pos+2) ? (pos+1) :  find(nums,(pos + n )/2));
        else return (pos == 0)?  0 : ((nums[pos-1] == pos-1) ? (pos) :  find(nums,(pos)/2));
    }
};



int main(){
    string input;
    vector<int> nums;
    Solution solution;

    cout << "please input " << endl;

    getline(cin,input, '\n');

    for(int i = input.find('[');i < input.find(']');i++ )   if(input[i] >= '0' && input[i] <= '9')  nums.push_back(input[i]-48);

    for(int i =0 ; i < nums.size();i++) cout << nums[i];
    
    //cout << "answer:" <<solution.missingNumber(nums) << endl;

    return 0;
}