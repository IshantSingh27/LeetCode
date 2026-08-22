class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long pre = 1 , post = 1 , ans = -1e9 , n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(pre == 0) pre = 1;
            if(post == 0) post = 1;

            pre *= nums[i];
            post *= nums[n - i - 1];

            ans = max(ans , max(pre , post));
        }
        return ans;
    }
};