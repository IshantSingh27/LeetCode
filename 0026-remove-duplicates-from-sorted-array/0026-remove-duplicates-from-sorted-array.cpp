class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1 , r = 1 , last = nums[0];
        while(r < nums.size()){
            if(nums[r] != last){
                // cout<<nums[r]<<" | "<<nums[l]<<endl;
                last = nums[r];
                swap(nums[l] , nums[r]);
                l++;
            }
            r++;
        }

        return l;
    }
};