// class MinStack {
// public:
// stack<pair<int , int>> st;
// int mini = INT_MAX;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(st.empty()){
//             mini = val;
//             st.push({val , mini});
//         }
//         else{
//             mini = min(mini , val);
//             st.push({val , mini});
//         }
//     }
    
//     void pop() {
//         if(st.empty()) return;
//         st.pop();
//         if(st.empty()){
//             mini = INT_MAX;
//             return;
//         }
//         mini = st.top().second;
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */
class MinStack {
public:
stack<long long> st;
long long mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if(val > mini) st.push(val);
            else{
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long n = st.top();
        st.pop();
        if(st.empty()){
            mini = INT_MAX;
            return;
        }
        if(n < mini) mini = (2LL * mini - n);
    }
    
    int top() {
        if(st.top() < mini) return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */