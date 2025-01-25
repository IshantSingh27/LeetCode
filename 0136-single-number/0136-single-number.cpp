// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         if(nums.size() == 1) return nums[0];
//         sort(nums.begin() , nums.end());

//         for(int i=0 ; i<nums.size()-1 ; i+=2){
//             // cout<<nums[i]<<" ";
//             if(nums[i] != nums[i+1]) return nums[i];
//         }
//         return nums[nums.size() - 1];
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=1 ; i<nums.size() ; i++){
            nums[0] = nums[0] ^ nums[i];
        }
        return nums[0];
    }
};