class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        mp[0] = 1;
        int n = nums.size() , cnt = 0 , ans = 0;

        for(int i=0 ; i<n ; i++){
            if(nums[i] % 2 == 1) cnt++;

            int need = cnt - k;
            if(mp.find(need) != mp.end()){
                ans += mp[need];
            }

            mp[cnt]++;
        }

        return ans;
    }
};