class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        stack<int> st;
        for(int i=2 * n ; i>=0 ; i--){
            while(!st.empty() && arr[i % n] >= st.top()){
                st.pop();
            }

            if(!st.empty() && i < n){
                ans.push_back(st.top());
            }
            else if(i < n){
                ans.push_back(-1);
            }

            st.push(arr[i % n]);
        }
        reverse(ans.begin() , ans.end());

        return ans;
    }
};