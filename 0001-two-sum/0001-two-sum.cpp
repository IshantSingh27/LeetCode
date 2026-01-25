class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        unordered_map<int , int> mp;
        int n = nums.size();

        for(int i=0 ; i<n ; i++){
            if(mp.count(tar - nums[i])){
                return {i , mp[tar - nums[i]]};
            }
            else{
                mp[nums[i]] = i;
            }
        }

        return {};
    }
};