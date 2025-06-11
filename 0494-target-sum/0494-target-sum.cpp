class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int total = 0 , n = arr.size();
        for(int i=0 ; i<n ; i++){
            total += arr[i];
        }
        int sum = (total + d) / 2;
        if(total < abs(d) || (total + d) % 2 != 0) return 0;
        vector<int> prev(sum + 1 , 0) , cur(sum + 1 , 0);
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(arr[0] != 0 && arr[0] <= sum) prev[arr[0]] = 1;
        for(int ind = 1 ; ind < n ; ind++){
            for(int tar = 0 ; tar <= sum ; tar++){
                int notTake = prev[tar];
                int take = 0;
                if(arr[ind] <= tar){
                    take = prev[tar - arr[ind]];
                }
                cur[tar] = take + notTake;
            }
            prev = cur;
        }
        return prev[sum];
    }
};