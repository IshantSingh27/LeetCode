class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        unordered_map<int , int> mp;
        int n = arr.size();
        for(int i=0 ; i<n ; i++){
            if(mp.find(k - arr[i]) != mp.end()) return {i , mp[k - arr[i]]};
            else if(mp.find(arr[i]) == mp.end()) mp[arr[i]] = i;
        }
        return {-1 , -1};
    }
};