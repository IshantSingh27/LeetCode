class Solution {
public:
    int solve(vector<int>& arr, int k){
        int n = arr.size() , r = 0 , l = 0 , cnt = 0;
        unordered_map<int , int> mp;

        while(r < n){
            mp[arr[r]]++;

            while(mp.size() > k){
                mp[arr[l]]--;
                if(mp[arr[l]] == 0) mp.erase(arr[l]);
                l++;
            }

            if(mp.size() <= k) cnt += r -l + 1;
            r++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums , k) - solve(nums , k - 1);
    }
};