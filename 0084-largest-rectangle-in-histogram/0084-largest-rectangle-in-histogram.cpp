class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int ans = 0 , n = arr.size();

        for(int i=0 ; i<n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                int ele = st.top();
                st.pop();

                int left = -1 , right = i;
                if(!st.empty()) left = st.top();
                ans = max(ans , (right - left - 1) * arr[ele]);
            }

            st.push(i);
        }

        while(!st.empty()){
            int ele = st.top();
            st.pop();
            int right = n;
            int left = -1;
            if(!st.empty()) left = st.top();

            ans = max(ans , (right - left - 1) * arr[ele]);
        }

        return ans;
    }
};