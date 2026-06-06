class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        vector<int> prev(2 , 0) , cur(2 , 0);

        for(int i=n-1 ; i>=0 ; i--){
            for(int j=0 ; j<2 ; j++){
                int profit = 0;
                if(j){
                    profit = max(prev[j] , prev[0] - arr[i]);
                }
                else profit = max(prev[j] , prev[1] + arr[i] - fee);
                cur[j] = profit;
            }
            prev = cur;
        }
        return prev[1];
    }
};