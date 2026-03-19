class Solution {
public:
    vector<int> nextsmall(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

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
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0 ; i<n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextsmall(arr);
        vector<int> pse = prevsmall(arr);
        int n = arr.size() , tot = 0 , mod = 1e9 + 7;

        for(int i=0 ; i<n ; i++){
            long long right = (nse[i] - i);
            long long left = (i - pse[i]);
            tot = (tot + ((right * left) % mod * arr[i] * 1LL) % mod) % mod;
        }

        return tot;
    }
};