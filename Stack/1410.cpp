class Solution {
private:
    unordered_map<string , char > m = {
        {"&quot;",'"'},{"&apos;",'\''},
        {"&amp;",'&'},{"&gt;",'>'},
        {"&lt;",'<'},{"&frasl;",'/'}
    };
    string res;
public:
    string entityParser(string text) {
        if(!text.size()) return {};
        for(int i = 0 ; i < text.size(); i++)
        {
            if(text[i] == '&')
            {
                int e_pos = transfer(text ,i);
                if(e_pos != -1) 
                {
                    i = e_pos;
                    continue;
                }
            }
            res+=text[i];
        }
        return res;
    }

    int transfer(string& text , int s_pos )
    {
        for(int i = s_pos+1; i <= s_pos + 6 ; i ++)
        {
            if(text[i] == ';')
            {
                if(m.find(text.substr(s_pos, i - s_pos+1)) != m.end())
                {
                    res+=m[text.substr(s_pos, i - s_pos+1)];
                    return i;
                }
            }
        }
        return -1;  
    }
};