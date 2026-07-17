class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size() , ans = 0;
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int cur = st.top() , left = -1 , right = i;
                st.pop();
                if(!st.empty()) left = st.top();

                int area = (right - left - 1) * heights[cur];
                ans = max(ans , area);
            }

            st.push(i);
        }

        while(!st.empty()){
            int cur = st.top() , left = -1 , right = n;
            st.pop();
            if(!st.empty()) left = st.top();
            int area = (right - left - 1) * heights[cur];
            ans = max(ans , area);
        }

        return ans;
    }
};