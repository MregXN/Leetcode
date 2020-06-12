// 搜索旋转数组。给定一个排序后的数组，包含n个整数，但这个数组已被旋转过很多次了，次数不详。请编写代码找出数组中的某个元素，假设数组元素原先是按升序排列的。若有多个相同元素，返回索引值最小的一个。

// 示例1:

//  输入: arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 5
//  输出: 8（元素5在该数组中的索引）
// 示例2:

//  输入：arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 11
//  输出：-1 （没有找到）
// 提示:

// arr 长度范围在[1, 1000000]之间

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {

    int n = arr.size();

    for(int i = 0 ; i < arr.size();i++)
    {
        if(arr[i] == target) return i ;
    } 

    return -1 ;
    }
};

int main(){
    string input;
    vector<int> arr;
    int target ;
    Solution solution;

    getline(cin,input,'\n');
    
    int temp = 0 ;

    for(int i = input.find('[') ; i <= input.find(']');i++)
    {
        if(isdigit(input[i])) temp = temp*10 + (input[i]- '0');
        else if(input[i] == ',' || input[i] == ']') 
        {
            arr.push_back(temp);
            temp = 0;
        }
    }

    for(int i = 0 ; i < arr.size(); i ++) cout << arr[i] << ',' << endl;

    target = 11;

    cout << solution.search(arr,target)  << endl;

    return 0 ;
}