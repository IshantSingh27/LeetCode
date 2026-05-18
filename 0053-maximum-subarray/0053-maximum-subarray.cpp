class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int sum = 0 , n = arr.size() , ans = -1e9;

        for(int i=0 ; i<n ; i++){
            sum += arr[i];

            ans = max(sum , ans);

            if(sum < 0){
                sum = 0;
            }
        }

        return ans;
    }
};