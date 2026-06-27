class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int ans = 0;
        for(int i=0 ; i<arr.size() ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                int ele = st.top();
                st.pop();

                int left = -1 , right = i;
                if(!st.empty()){
                    left = st.top();
                }

                ans = max(ans , (right - left - 1) * arr[ele]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int ele = st.top();
            st.pop();
            int right = arr.size() , left = -1;
            if(!st.empty()) left = st.top();

            ans = max(ans , (right - left - 1) * arr[ele]);   
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& nums) {
        int n = nums.size() , m = nums[0].size();
        vector<vector<int>> arr(n , vector<int>(m , 0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(nums[i][j] == '1'){
                    arr[i][j] = 1;
                    if(i > 0) arr[i][j] += arr[i-1][j];
                }
                else{
                    arr[i][j] = 0;
                }
            }
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            ans = max(ans , largestRectangleArea(arr[i]));
        }
        return ans;
    }
};