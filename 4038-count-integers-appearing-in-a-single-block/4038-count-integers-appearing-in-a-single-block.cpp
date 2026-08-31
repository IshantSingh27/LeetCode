class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int , int> mp;
        int n = nums.size() , cnt = 0;

        for(int i=0 ; i<n ; i++){
            if(i > 0 && nums[i] != nums[i - 1] && mp.find(nums[i]) != mp.end() && mp[nums[i]] != 2){
                cnt++;
                mp[nums[i]] = 2;

            }
            else if((i == 0 || nums[i] != nums[i - 1]) && mp[nums[i]] != 2) mp[nums[i]] = 1;
        }

        return max(0 , (int)mp.size() - cnt);
    }
};