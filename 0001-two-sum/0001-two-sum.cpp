class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int , int> mp;

        for(int i=0 ; i<arr.size() ; i++){
            int num = arr[i];
            int rem = tar - arr[i];
            if(mp.find(rem) != mp.end()){
                return {i , mp[rem]};
            }
            mp[num] = i;
        }

        return {-1};
    }
};