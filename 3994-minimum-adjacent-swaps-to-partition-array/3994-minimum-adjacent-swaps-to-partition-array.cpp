class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long cnt1 = 0 , cnt2 = 0 , cnt3 = 0 , ans = 0 , mod = 1e9 + 7;
        for(long long i=0 ; i<nums.size() ; i++){
            int type;
            if(nums[i] < a) type = 0;
            else if(nums[i] <= b && nums[i] >= a) type = 1;
            else type = 2;

            if(type == 0){
                ans = (ans + cnt2 + cnt3) % mod;
                cnt1++;
            }
            else if(type == 1){
                ans = (ans + cnt3) % mod;
                cnt2++;
            }
            else cnt3++;
        }
        return ans;
    }
};