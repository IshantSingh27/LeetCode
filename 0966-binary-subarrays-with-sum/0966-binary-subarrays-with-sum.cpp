class Solution {
public:
    int solve(vector<int>& arr, int k){
        if(k < 0) return 0;
        int n = arr.size() , cnt = 0 , l = 0 , r = 0 , sum = 0;
        while(r < n){
            sum += arr[r];
            while(sum > k){
                sum -= arr[l];
                l++;
            }
            if(sum <= k){
                cnt += r - l + 1;
            }
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums , goal) - solve(nums , goal - 1);
    }
};