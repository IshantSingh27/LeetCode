class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int l = 0 , r = 0 , ans = 0 , cnt = 0;

        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] == 0) cnt++;

            if(cnt > k){
                if(arr[l] == 0) cnt--;
                l++;
            }

            if(cnt <= k){
                ans = i - l + 1;
            }
        }

        return ans;
    }
};