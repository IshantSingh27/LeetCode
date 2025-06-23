class Solution {
public:
    int solve(vector<int>& arr , int k){
        if( k < 0) return 0;
        int n = arr.size() , sum = 0 , cnt = 0 , l = 0 , r = 0;
        while(r < n){
            sum += arr[r] % 2;
            while(sum > k){
                sum -= arr[l] % 2;
                l++;
            }
            if(sum <= k) cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums , k) - solve(nums , k - 1);
    }
};