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
            if(!st.empty() && arr[st.top()] <= arr[ele]) left = st.top();

            ans = max(ans , (right - left - 1) * arr[ele]);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>> pre(n , vector<int>(m , 0));
        for(int i=0 ; i<m ; i++){
            int sum = 0;
            for(int j=0 ; j<n ; j++){
                if(arr[j][i] == '0') sum = 0;
                else{
                    sum += 1;
                    pre[j][i] = sum;
                }
            }
        }

        int ans = 0;
        for(int i=0 ; i<n ; i++){
            int temp = largestRectangleArea(pre[i]);

            ans = max(ans , temp);
        }

        return ans;
    }
};