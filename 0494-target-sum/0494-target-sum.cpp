class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int n = arr.size() , sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += arr[i];
        }
        int k = (sum - d);
        if(k < 0 || k % 2 == 1) return 0;
        else k = k / 2;
        
        vector<int> prev(k + 1 , 0) , cur(k + 1 , 0);
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<=k ; j++){
                int nottake = prev[j];
                int take = 0;
                if(arr[i] <= j) take = prev[j - arr[i]];
                cur[j] = take + nottake;
            }
            prev = cur;
        }
        return prev[k];
    }
};