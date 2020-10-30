class Solution {
    vector<int> a = vector<int>(26,0);
public:
    string sortString(string s) {
        if(!s.size()) return {};
        string res;
        for(auto c : s)
        {
            a[c-'a']++;    
        }


        int n = s.size();

        while(n--)
        {
            for(int i = 0 ; i < 26 ; i++)
            {
                if(a[i]) 
                {
                    res += char(i+'a');
                    a[i]--;
                }
            }    

            for(int i = 25 ; i >=0 ; i--)
            {
                if(a[i]) 
                {
                    res += char(i+'a');
                    a[i]--;
                }
            }    

        }

        return res;
        
    }
};