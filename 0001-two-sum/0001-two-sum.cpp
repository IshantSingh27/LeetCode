class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        unordered_map<int , int> mp;
        mp[arr[0]] = 0;
        int n = arr.size();

        for(int i=1 ; i<n ; i++){
            int need = k - arr[i];
            if(mp.find(need) != mp.end()){
                return {mp[need] , i};
            }
            mp[arr[i]] = i;
        }

        return {0 , 0};
    }
};