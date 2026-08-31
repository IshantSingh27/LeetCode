class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> block(101 , 0);
        for(int i=0 ; i<nums.size() ; i++){
            if(i == 0 || nums[i] != nums[i - 1]) block[nums[i]]++;
        }

        int ans = 0;
        for(int i=1 ; i<101 ; i++){
            if(block[i] == 1) ans++;
        }

        return ans;
    }
};