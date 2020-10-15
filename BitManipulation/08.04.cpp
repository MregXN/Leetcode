// 幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

// 说明：解集不能包含重复的子集。

// 示例:

//  输入： nums = [1,2,3]
//  输出：
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int temp = (1<<nums.size()) -1;
        vector<vector<int>> res;
        while(temp >=0)
        {
            vector<int> res_temp;
            for(int i = 0 ; i <nums.size(); i++) if(temp &  (1<<i) ) res_temp.push_back(nums[i]);

            temp--;
            res.push_back(res_temp);
        }
        return res;
    }
};