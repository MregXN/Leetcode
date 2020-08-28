// 给定两个数组，编写一个函数来计算它们的交集。

//  

// 示例 1：

// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
// 输出：[2]
// 示例 2：

// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// 输出：[9,4]
//  

// 说明：

// 输出结果中的每个元素一定是唯一的。
// 我们可以不考虑输出结果的顺序。

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_map <int,int> m;

        for (auto a : nums1) m[a] = 0;
        vector<int> res;

        for(auto a : nums2) 
        {

            if( m.find(a) != m.end() ) 
            {
                if(m[a] == 0)res.push_back(a);
                m[a] ++;
            }
        }

        return res;

    }
};


int main(){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};

    Solution so;

    so.intersection(nums1,nums2);

    return 0;
}