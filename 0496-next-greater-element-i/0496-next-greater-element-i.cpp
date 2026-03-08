class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& arr) {
        stack<int> st;
        unordered_map<int , int> mp;
        
        for(int i=arr.size() - 1 ; i>=0 ; i--){
            while(!st.empty() && arr[i] >= st.top()){
                st.pop();
            }
            
            if(st.empty()) mp[arr[i]] = -1;
            else{
                mp[arr[i]] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        vector<int> res;
        for(int i=0 ; i<nums.size() ; i++){
            res.push_back(mp[nums[i]]);
        }

        return res;
    }
};