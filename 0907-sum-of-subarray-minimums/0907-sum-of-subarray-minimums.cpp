class Solution {
public:
    vector<int> nextsmall(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);

        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> prevsmall(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);

        for(int i=0 ; i<n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextsmall(arr);
        vector<int> pse = prevsmall(arr);
        long long tot = 0 , n = arr.size() , mod = 1e9 + 7;

        for(int i=0 ; i<n ; i++){
            tot = ( tot + (( ( (nse[i] - i) * (i - pse[i]) ) % mod) * arr[i] * 1LL ) % mod ) % mod;
        }

        return tot;
    }
};