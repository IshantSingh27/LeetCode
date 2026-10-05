class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() , pre = 1 , post = 1 , ans = -1e9;

        for(int i=0 ; i<n ; i++){
            if(pre == 0) pre = 1;
            if(post == 0) post = 1;

            pre = pre * nums[i];
            post = post * nums[n - i - 1];

            ans = max(ans , max(pre , post));
        }

        return ans;
    }
};