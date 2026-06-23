class StockSpanner {
public:
stack<pair<int , int>> st;
int ind;
    StockSpanner() {
        ind = -1;
    }
    
    int next(int val) {
        ind++;
        while(!st.empty() && val >= st.top().first){
            st.pop();
        }

        int ans = 1;
        if(!st.empty()) ans = ind - st.top().second;
        else ans = ind + 1;
        st.push({val , ind});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */