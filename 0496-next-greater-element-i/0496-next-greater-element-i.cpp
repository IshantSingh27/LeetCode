class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& arr) {
        stack<int> st;
        vector<int> ans(arr.size());
        
        for(int i=arr.size() - 1 ; i>=0 ; i--){
            while(!st.empty() && arr[i] >= st.top()){
                st.pop();
            }
            
            if(st.empty()) ans[i] = -1;
            else{
                ans[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        vector<int> res;
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=0 ; j<arr.size() ; j++){
                if(nums[i] == arr[j]){
                    res.push_back(ans[j]);
                }
            }
        }

        return res;
    }
};