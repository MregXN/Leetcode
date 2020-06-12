// 给你一个整数数组 arr 和两个整数 k 和 threshold 。

// 请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。

//  

// 示例 1：

// 输入：arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
// 输出：3
// 解释：子数组 [2,5,5],[5,5,5] 和 [5,5,8] 的平均值分别为 4，5 和 6 。其他长度为 3 的子数组的平均值都小于 4 （threshold 的值)。
// 示例 2：

// 输入：arr = [1,1,1,1,1], k = 1, threshold = 0
// 输出：5
// 示例 3：

// 输入：arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
// 输出：6
// 解释：前 6 个长度为 3 的子数组平均值都大于 5 。注意平均值不是整数。
// 示例 4：

// 输入：arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
// 输出：1
// 示例 5：

// 输入：arr = [4,4,4,4], k = 4, threshold = 1
// 输出：1
//  

// 提示：

// 1 <= arr.length <= 10^5
// 1 <= arr[i] <= 10^4
// 1 <= k <= arr.length
// 0 <= threshold <= 10^4


#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int n = arr.size();
        int sum = 0;
        int count = 0;
        for(int i = 0 ; i < k  ; i++ ) sum+= arr[i];

        if (sum >= k * threshold) count++;

        for(int i = 0 ; i < n - k ; i++ )
        {
            sum = sum - arr[i] + arr[i+k];
            if (sum >= k * threshold) count++;
        }

        return count;

    }
};


int main(){
    vector<int> arr;
    int k,threshold;
    string input;
    Solution solution;

    getline(cin, input , '\n');
    for(int i = input.find('['); i < input.find(']') ; i ++) if(isdigit(input[i])) arr.push_back(input[i] - '0' );

    k = input[input.rfind(',') - 1] - '0';
    threshold = input[input.size() - 1] - '0';

    
    for(int i = 0 ; i < arr.size(); i ++) cout << arr[i] << ',' << endl;
    cout << k << ',' << endl;
    cout << threshold << ',' << endl;
    cout << solution.numOfSubarrays(arr,k,threshold) << endl;

    return 0 ;
}