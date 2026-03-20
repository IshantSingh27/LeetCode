class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size() , r = 0 , l = 0 , cnt = 0 , ans = 0;

        while(r < n){
            if(arr[r] == 0) cnt++;

            if(cnt > k){
                if(arr[l] == 0) cnt--;
                l++;
            }

            if(cnt <= k){
                ans = max(ans , r - l + 1);
            }

            r++;
        }
        return ans;
    }
};