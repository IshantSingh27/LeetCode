class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size() , ans = 0;
        stack<int> st;
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                int ele = arr[st.top()];
                st.pop();

                int left = -1 , right = i;
                if(!st.empty()) left = st.top();
                ans = max(ans , ((right - left) - 1) * ele);
            }
            st.push(i);
        }

        while(!st.empty()){
            int ele = arr[st.top()];
            st.pop();
            int right = n , left = -1;
            if(!st.empty()) left = st.top();
            ans = max(ans , ((right - left) - 1) * ele);
        }

        return ans;
    }
};