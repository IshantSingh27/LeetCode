class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        unordered_map<int , int> mp;
        int n = arr.size();

        for(int i=0 ; i<n ; i++){
            int rem = k - arr[i];

            if(mp.find(rem) != mp.end()){
                return {mp[rem] , i};
            }

            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = i;
            }
        }

        return {-1};
    }
};