class Solution {
public:
long long mod = 1e9 + 7;
    vector<long long> nxt(vector<int>& arr){
        long long n = arr.size();
        vector<long long> ans(n , n);
        stack<long long> st;

        for(long long i=n-1 ; i>=0 ; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }
        return ans;
    }
    vector<long long> pre(vector<int>& arr){
        long long n = arr.size();
        vector<long long> ans(n , -1);
        stack<long long> st;

        for(long long i=0 ; i<n ; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<long long> nse = nxt(arr);
        vector<long long> pse = pre(arr);

        long long tot = 0;
        for(long long i=0 ; i<arr.size() ; i++){
            tot = tot + (( ((nse[i] - i) * (i - pse[i]) % mod) * arr[i] * 1LL) % mod) % mod;
        }

        return tot % mod;
    }
};