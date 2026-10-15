class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() , i = n - 2 , j = n - 1;

        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }

        if(i < 0){
            reverse(nums.begin() , nums.end());
            return;
        }

        while(j > i){
            if(nums[j] > nums[i]) break;
            j--;
        }

        swap(nums[i] , nums[j]);

        reverse(nums.begin() + i + 1 , nums.end());
    }
};