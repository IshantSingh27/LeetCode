class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k , 0);
        freq[0] = 1;
        int n = nums.size() , sum = 0 , ans = 0;

        for(int i=0 ; i<n ; i++){
            sum += nums[i];

            int rem = sum % k;

            if(rem < 0) rem += k;

            ans += freq[rem];

            freq[rem]++;
        }

        return ans;
    }
};