// 给定两个整数数组a和b，计算具有最小差绝对值的一对数值（每个数组中取一个值），并返回该对数值的差

// 示例：

// 输入：{1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
// 输出： 3，即数值对(11, 8)
// 提示：

// 1 <= a.length, b.length <= 100000
// -2147483648 <= a[i], b[i] <= 2147483647
// 正确结果在区间[-2147483648, 2147483647]内
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) 
    {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long ret = INT_MAX;
        for(int i = 0, j = 0; i < a.size() && j < b.size();)
        {
            ret = min(ret,abs(long(a[i])-long(b[j])));
            if(a[i] < b[j]){
                i++;
            }else{
                j++;
            }
        }
        return ret;
    }
};


class Solution {
public:
    
    
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        double ans = 3e9;
        for(int i = 0; i < b.size(); i ++){
            int l = 0, r = (int)a.size() - 1;
            while(l < r){
                int mid = l + r + 1>> 1;
                if(a[mid] <= b[i]) l = mid;
                else r = mid - 1;
            }
            ans = min(ans, (double)abs((double)a[l] - (double)b[i]));
            if(l != (int)a.size() - 1) ans = min(ans, (double)abs((double)a[l + 1] - (double)b[i]));
        }
        return ans;
    }
};
