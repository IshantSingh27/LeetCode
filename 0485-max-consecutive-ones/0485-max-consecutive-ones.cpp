class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int l = 0 , r = 0 , n = arr.size() , ans = 0;
        while(r < n){
            if(arr[r] == 1){
                ans = max(ans , r - l + 1);
                r++;
            }
            else{
                r++;
                l = r;
            }
        }

        return ans;
    }
};