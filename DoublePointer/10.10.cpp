// 面试题 10.01. 合并排序的数组
// 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

// 初始化 A 和 B 的元素数量分别为 m 和 n。

// 示例:

// 输入:
// A = [1,2,3,0,0,0], m = 3
// B = [2,5,6],       n = 3

// 输出: [1,2,2,3,5,6]
// 说明:

// A.length == n + m

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> C(A.size());
        int i = 0, j = 0; //定义双指针 
        while(i < m || j < n) {
            if(i == m) C[i + j - 1] = B[j ++]; //A已遍历m个
            else if(j == n || A[i] < B[j]) C[i + j -1 ] = A[i ++]; //B已遍历n个,或A[i] < B[j] 
            else C[i + j -1] = B[j ++]; //A[i] >= B[j] 
        }
        A = C;
    }
};

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1;
        int k = A.size() - 1;
        while(i >= 0 || j >= 0) {
            if(i == -1) A[k --] = B[j --]; //A已遍历m个
            else if(j == -1 || A[i] > B[j]) A[k --] = A[i --]; //B已遍历n个，或A[i] > B[j] 
            else A[k --] = B[j --]; //A[i] <= B[j] 
        }
    }
};