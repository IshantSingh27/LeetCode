class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        unordered_map<int , int> mp;

        for(int i=0 ; i<nums.size() ; i++){
            if(mp.count(tar - nums[i])){
                return {mp[tar - nums[i]] , i};
            }
            else{
                mp[nums[i]] = i;
            }
        }

        return {};
    }
};