class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        unordered_map<int , int> mp;
        int n = nums.size();

        for(int i=0 ; i<n ; i++){
            if(mp.find(tar - nums[i]) != mp.end()){
                return {i , mp[tar - nums[i]]};
            }
            else{
                mp[nums[i]] = i;
            }
        }

        return {};
    }
};