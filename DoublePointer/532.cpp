class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(!nums.size()) return 0;
        if( k < 0) return 0;
        int res = 0;
        unordered_map<int ,int > m ;

        for(int i = 0 ;i < nums.size()-1;i++)
        {
            for(int j = i+1 ; j < nums.size();j++)
            {
                if( (nums[i] - nums[j] == k) || (nums[j] - nums[i] == k) ) 
                {
                    if(m.find( nums[i] + nums[j])  == m.end())
                        res++;
                        m[nums[i] + nums[j]] =1;

                }
            }
        }

        return res;
    }
};