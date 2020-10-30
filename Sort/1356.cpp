class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }

    static bool comp(int x, int y)
    {
        bitset<32> a(x);
        bitset<32> b(y);
        return a.count() < b.count()?(true):( a.count() == b.count()? (x<y) :false);
    }
};
