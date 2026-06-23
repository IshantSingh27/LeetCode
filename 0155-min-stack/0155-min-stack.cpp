class MinStack {
public:
    stack<pair<int  ,int>> st;
    int mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mini = val;
            st.push({val , mini});
        }
        else{
            mini = min(mini , val);
            st.push({val , mini});
        }
    }
    
    void pop() {
        st.pop();
        if(st.empty()){
            mini = INT_MAX;
        }
        else{
            mini = st.top().second;
        }
    }
    
    int top() {
        if(!st.empty()) return st.top().first;
        return -1;
    }
    
    int getMin() {
        if(!st.empty()) return st.top().second;
        return INT_MAX;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */