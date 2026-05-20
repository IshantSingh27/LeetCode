class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int , int> mp;
        mp[0] = 1; //so we do not need (presum == k) cnt++ as if equal then k = 0 so mp[0] = 1 added
        int presum = 0 , n = arr.size() , cnt = 0;

        for(int i=0 ; i<n ; i++){
            presum += arr[i];

            int need = presum - k;
            if(mp.find(need) != mp.end()){
                cnt += mp[need];
            }

            mp[presum]++;
        }

        return cnt;
    }
};