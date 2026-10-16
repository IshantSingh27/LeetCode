class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> bef(n) , aft(n) , ans(n);

        bef[0] = 1;
        for(int i=1 ; i<n ; i++){
            bef[i] = nums[i - 1] * bef[i - 1];
        }

        aft[n - 1] = 1;
        for(int i=n - 2 ; i>=0 ; i--){
            aft[i] = nums[i + 1] * aft[i + 1];
        }

        for(int i=0 ; i<n ; i++){
            ans[i] = bef[i] * aft[i];
        }

        return ans;
    }
};