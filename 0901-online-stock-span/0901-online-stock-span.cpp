class StockSpanner {
public:
    stack<pair<int , int>> st;
    StockSpanner() {
        
    }
    
    int next(int val) {
        if(st.empty()){
            st.push({val , 1});
            return 1;
        }
        else{
            if(val >= st.top().first){
                int n = st.top().second + 1;
                st.pop();
                while(!st.empty() && st.top().first <= val){
                    n += st.top().second;
                    st.pop();
                }
                st.push({val , n});
                return n;
            }
            else{
                st.push({val , 1});
                return 1;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */