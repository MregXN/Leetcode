class Solution {
private:
    stack<int> score;
public:
    int calPoints(vector<string>& ops) {
        int res;

        for(auto cmd : ops)
        {
            if(!cmd.compare("+") )
            {
                int s1 = score.top();
                score.pop();
                int s2 = score.top();
                score.push(s1);
                score.push(s1+s2);
                res += (s1 + s2);
            }
            else if(!cmd.compare("D")  )
            {
                int s1 = score.top();
                score.push(s1*2);
                res += (s1 *2);
            }
            else if(!cmd.compare("C")  )
            {
                int s1 = score.top();
                score.pop();
                res -= s1;
            }
            else
            {
                score.push(stoi(cmd));
                res += stoi(cmd);
            }
        }
        return res;
    }
};