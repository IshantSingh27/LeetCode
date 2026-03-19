class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i=0 ; i<n ; i++){
            if(arr[i] >= 0){
                st.push(arr[i]);
                // cout<<"push hua"<<endl;
            }
            else{
                if(!st.empty() && st.top() >= 0){
                    while(!st.empty() && st.top() >= 0 && st.top() < abs(arr[i])){
                        st.pop();
                        // cout<<"pop hua"<<endl;
                    }
                    if(st.empty()) st.push(arr[i]);
                    else if(st.top() == abs(arr[i])) st.pop();
                    else if(st.top() < 0) st.push(arr[i]);
                }
                else{
                    st.push(arr[i]);
                }
            }
        }
        // cout<<"Size : "<<st.size()<<endl;
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());

        return ans;
    }
};