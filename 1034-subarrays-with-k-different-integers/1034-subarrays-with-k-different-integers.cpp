class Solution {
public:
    int solve(vector<int>& s , int k){
        if(k <= 0) return 0;
        int n = s.size() , l = 0 , r = 0 , cnt = 0;
        unordered_map<int , int> mp;

        while(r < n){
            mp[s[r]]++;

            while(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
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