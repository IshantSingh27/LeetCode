class Solution {
public:
    int solve(vector<int>& arr, int k){
        if(k < 0) return 0;
        int n = arr.size() , cnt = 0 , l = 0 , r = 0;
        unordered_map<int, int> mp;
        while(r < n){
            mp[arr[r]]++;
            while(mp.size() > k){
                mp[arr[l]]--;
                if(mp[arr[l]] == 0) mp.erase(arr[l]);
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums , k) - solve(nums , k - 1);
    }
};