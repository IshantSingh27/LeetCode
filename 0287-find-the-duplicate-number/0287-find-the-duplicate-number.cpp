class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> arr(nums.size() + 1 , 0);
        for(auto it : nums){
            if(arr[it] == 1) return it;
            else arr[it] = 1;
        }
        return -1;
    }
};