class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0 , maxi = 0;

        for(int i=k ; i<n ; i++){
            maxi = max(maxi , nums[i - k]);

            ans = max(ans , nums[i] + maxi);
        }

        return ans;
    }
};