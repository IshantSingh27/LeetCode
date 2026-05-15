class Solution {
public:
    int sol(vector<int>& arr, int k){
        if(k < 0) return 0;
        int l = 0 , r = 0 , cnt = 0 , sum = 0;

        while(r < arr.size()){
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
    int numSubarraysWithSum(vector<int>& arr, int k) {
        return sol(arr , k) - sol(arr , k - 1);
    }
};