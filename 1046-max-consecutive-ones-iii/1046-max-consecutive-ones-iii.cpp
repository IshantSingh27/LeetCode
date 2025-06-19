class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0 , r = 0 , zero = 0 , maxlen = 0;
        while(r < n){
            if(arr[r] == 0)  zero++;
            if(zero > k){
                if(arr[l] == 0) zero--;
                l++;
            }
            if(zero <= k){
                maxlen = max(maxlen , r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};