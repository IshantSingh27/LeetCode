// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<pair<int , int>> arr(n);
//         for(int i=0 ; i<n ; i++){
//             arr[i].first = nums[i];
//             arr[i].second = i;
//         }

//         sort(arr.begin() , arr.end());

//         int i=0 , j=n-1;
//         while(i < j){
//             if(arr[i].first + arr[j].first == target){
//                 return {arr[i].second , arr[j].second};
//             }
//             else if(arr[i].first + arr[j].first < target){
//                 i++;
//             }
//             else{
//                 j--;
//             }
//         }
//         return {-1 , -1};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int> mp;

        for(int i=0 ; i<n ; i++){
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end()){
                return {mp[rem] , i};
            }
            mp[nums[i]] = i;
        }

        return{-1 , -1};
    }
};