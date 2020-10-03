class Solution {
public:
    string makeGood(string s) {
        string stack;
        for(int i = 0; i < s.size(); i++){
            stack += s[i];
            int n = stack.size();
            if(n >= 2 && (stack[n-1] + 32 == stack[n-2] || stack[n-1] - 32 == stack[n-2])) {
                stack.resize(n-2);
            }
        }
        return stack;
    }
};