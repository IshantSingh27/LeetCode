class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size() , presum = 0 , cnt = 0;
        unordered_map<int , int> mp;
        mp[0] = 1;

        for(int i=0 ; i<n ; i++){
            presum += arr[i];
            int rem = presum - k;
            cnt += mp[rem];
            mp[presum]++;
        }

        return cnt;
    }
};