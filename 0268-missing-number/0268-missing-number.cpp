class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = nums.size();

        for(int i=0 ; i<nums.size() ; i++){
            x = x ^ nums[i] ^ i;
        }

        return x;
    }
};