// 给定一个编码字符串 S。请你找出 解码字符串 并将其写入磁带。解码时，从编码字符串中 每次读取一个字符 ，并采取以下步骤：

// 如果所读的字符是字母，则将该字母写在磁带上。
// 如果所读的字符是数字（例如 d），则整个当前磁带总共会被重复写 d-1 次。
// 现在，对于给定的编码字符串 S 和索引 K，查找并返回解码字符串中的第 K 个字母。

//  

// 示例 1：

// 输入：S = "leet2code3", K = 10
// 输出："o"
// 解释：
// 解码后的字符串为 "leetleetcodeleetleetcodeleetleetcode"。
// 字符串中的第 10 个字母是 "o"。
// 示例 2：

// 输入：S = "ha22", K = 5
// 输出："h"
// 解释：
// 解码后的字符串为 "hahahaha"。第 5 个字母是 "h"。
// 示例 3：

// 输入：S = "a2345678999999999999999", K = 1
// 输出："a"
// 解释：
// 解码后的字符串为 "a" 重复 8301530446056247680 次。第 1 个字母是 "a"。
//  

// 提示：

// 2 <= S.length <= 100
// S 只包含小写字母与数字 2 到 9 。
// S 以字母开头。
// 1 <= K <= 10^9
// 题目保证 K 小于或等于解码字符串的长度。
// 解码后的字符串保证少于 2^63 个字母。

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string  ss;
        for(auto c :S)
        {
            if(isalpha(c))
            {
                ss+=c;
                if(ss.size() == K) return string(1,c);
            }
            else{
                if(ss.size()*(c - '0') < K) 
                {
                    int n = c - '0' -1;
                    string temp = ss;
                    while(n--) ss += temp;
                }
                else
                {
                    K %= ss.size();
                    cout << K << endl;
                    return string(1,ss[K-1 < 0 ? ss.size()-1 : K-1 ]);
                }
            }
            cout << ss << endl;
        }

        return "";
    }
};

class Solution {
public:
	bool IsDigital(char numChr) 
	{
		if (numChr > '0' && numChr <= '9') {
			return true;
		}
		return false;
	}
    string decodeAtIndex(string S, int K) {
		if (S.empty()) {
			return "";
		}
		long long currentStrLength = 0;
		int index = 0;
		for (; index < S.length(); index++) {
			if (IsDigital(S[index])) {
				currentStrLength *= (S[index] - '0');
			} else {
				currentStrLength++;
			}
			if (currentStrLength >= K) {
				break;
			}
		}
		for (int j = index; j >= 0; j--) {
			if (IsDigital(S[j])) {
				currentStrLength = currentStrLength / (S[j] - '0');
				K = K % currentStrLength;
			} else {
				if (K % currentStrLength == 0) {
					return string(1, S[j]);
				}
				currentStrLength--;
			}
		}
        return "";
    }
};