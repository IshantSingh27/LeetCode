class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        vector<int> prev(2) , cur(2);
        for(int ind = n - 1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy){
                    profit = max(prev[0] - arr[ind] , prev[1] - 0);
                }
                else{
                    profit = max(prev[1] + arr[ind] - fee , prev[0] + 0);
                }
                cur[buy] = profit;
            }
            prev = cur;
        }
        return prev[1];
    }
};