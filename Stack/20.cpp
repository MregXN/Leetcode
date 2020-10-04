class Solution {
public:
    bool isValid(string s) {
        if(!s.size()) return true;

        unordered_map<char,char> m  = 
        {  {')','('}, 
           {']','['},
           {'}','{'} };

        stack<char> ss;


        for(auto c:s)
        {
            switch(c)
            {
                case ')':
                case ']':
                case '}':
                    if(ss.empty()) return false;
                    if(ss.top()!= m[c]) return false;
                    ss.pop();
                break;

                default:
                    ss.push(c);
                break;

            }
        }


        return ss.empty();
    }
};