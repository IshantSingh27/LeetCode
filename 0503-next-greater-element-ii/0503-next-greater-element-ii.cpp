class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=2 * n ; i>=0 ; i--){
            while(!st.empty() && arr[i % n] >= st.top()){
                st.pop();
            }

            if(!st.empty() && i < n){
                ans[i] = st.top();
            }
            else if(i < n){
                ans[i] = -1;
            }

            st.push(arr[i % n]);
        }
        return ans;
    }
};