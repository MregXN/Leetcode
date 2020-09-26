// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

//  

// 示例 1：

// 输入：S = "ababcbacadefegdehijhklij"
// 输出：[9,7,8]
// 解释：
// 划分结果为 "ababcbaca", "defegde", "hijhklij"。
// 每个字母最多出现在一个片段中。
// 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
//  

// 提示：

// S的长度在[1, 500]之间。
// S只包含小写字母 'a' 到 'z' 。
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.size() == 1 ) return {1};
        unordered_map< int , pair< int , int >> m;

        for(int i = 0 ; i <  S.size() ; i ++)
        {
            if(m.find(S[i]) == m.end()) m[S[i]] = {i,i};
            else m[S[i]].second = i;
        }

        int threshold = m[S[0]].second;
        vector<int> res  ;

        for(int i = 0 ; i <  S.size() ; i ++)
        {
            if(m[S[i]].second > threshold) threshold = m[S[i]].second;
            if( i== threshold) res.emplace_back(i);
        }


        for(int i = 1 ; i < res.size();i++)
        {
            res[i] = res[i] - res[i-1];
        }
        res[0]++;

          return res;
    }
};


class Solution {
public:
    vector<int> partitionLabels(string S) {
        int N = S.size();
        vector<int> ends(26, -1);
        for (int i = 0; i < N; ++i) {
            ends[S[i] - 'a'] = i;
        }
        vector<int> res;
        int i = 0;
        while (i < N) {
            int r = ends[S[i] - 'a'];
            for (int j = i + 1; j <= r; ++j) {
                r = max(r, ends[S[j] - 'a']);
            }
            res.push_back(r - i + 1);
            i = r + 1;
        }
        return res;
    }
};