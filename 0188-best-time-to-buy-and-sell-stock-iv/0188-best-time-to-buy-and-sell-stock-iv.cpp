class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> prev(2 , vector<int>(k + 1 , 0)) , cur(2 , vector<int>(k + 1 , 0));

        // for(int j=0 ; j<=1 ; j++){
        //     prev[j][0] = 0;
        //     cur[j][0] = 0;
        // }
        // for(int i=0 ; i<=1 ; i++){
        //     for(int j=0 ; j<=k ; j++){
        //         prev[i][j] = 0;
        //     }
        // }

        for(int ind=n-1 ; ind>=0 ; ind--){
            for(int buy=0 ; buy<=1 ; buy++){
                for(int cap=1 ; cap<=k ; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(prev[0][cap] - arr[ind] , prev[1][cap] - 0);
                    }
                    else{
                        profit = max(prev[1][cap - 1] + arr[ind] , prev[0][cap] + 0);
                    }

                    cur[buy][cap] = profit;
                }
            }
            prev = cur;
        }

        return prev[1][k];
    }
};