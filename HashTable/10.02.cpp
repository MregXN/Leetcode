// 编写一种方法，对字符串数组进行排序，将所有变位词组合在一起。变位词是指字母相同，但排列不同的字符串。

// 注意：本题相对原题稍作修改

// 示例:

// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// 说明：

// 所有输入均为小写字母。
// 不考虑答案输出的顺序。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string ,vector<string> > m;
        vector<vector<string>> res;
        for(auto s: strs)
        {
            string stemp = s;
            sort(stemp.begin(),stemp.end());
            m[stemp ].push_back(s);
        }

        for(auto it = m.begin(); it != m.end();it++) res.push_back(it->second);

        return res;
    }
};