class Solution {
public:
    int sol(vector<int>& nums, int k){
        unordered_map<int , int> mp;
        int i = 0 , n = nums.size() , j = 0 , ans = 0;

        while(i < n){
            mp[nums[i]]++;

            while(j < i && mp.size() > k){
                mp[nums[j]]--;

                if(mp[nums[j]] == 0) mp.erase(nums[j]);

                j++;
            }

            if(mp.size() <= k) ans += i - j + 1;
            i++;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sol(nums , k) - sol(nums , k - 1);
    }
};