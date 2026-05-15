class Solution {
public:
    int sol(vector<int>& arr, int k){
        if(k < 0) return 0;

        int cntodd = 0 , r = 0 , l = 0 , cnt = 0;
        while(r < arr.size()){
            if(arr[r] % 2 != 0) cntodd++;

            while(cntodd > k){
                if(arr[l] % 2 != 0) cntodd--;
                l++;
            }

            if(cntodd <= k){
                cnt += r - l + 1;
            }

            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& arr, int k) {
        return sol(arr , k) - sol(arr , k - 1);
    }
};