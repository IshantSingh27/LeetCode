class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin() , nums.end());
        int n = nums.size() , ans = 0;

        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1 , cur = it;

                while(st.find(cur + 1) != st.end()){
                    cnt++;
                    cur++;
                }

                ans = max(cnt , ans);
            }
        }

        return ans;
    }
};