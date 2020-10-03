class MinStack {
private:
    vector<int> data;
    
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data.push_back(x);
    }
    
    void pop() {
        data.erase(data.end()-1);
    }
    
    int top() {
        return *(data.end()-1);
    }
    
    int min() {
        int min_value = INT_MAX;
        for(int pos = 0; pos < data.size();pos++)
        {
            min_value = (min_value < data[pos]) ? min_value : data[pos] ; 
        }
        return min_value;
    }
};