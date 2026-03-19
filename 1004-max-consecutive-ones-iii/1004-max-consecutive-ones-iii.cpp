class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size() , left = 0 , zero = 0 , ans = 0;

        for(int right=0 ; right<n ; right++){
            if(arr[right] == 0) zero++;

            while(zero > k){
                if(arr[left] == 0) zero--;
                left++;
            }

            ans = max(ans , right - left + 1);
        }

        return ans;
    }
};