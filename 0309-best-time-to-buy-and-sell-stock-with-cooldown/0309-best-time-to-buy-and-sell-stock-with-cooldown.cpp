class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev1(2) , cur(2) ,
        prev2(2);
        for(int ind = n - 1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy){
                    profit = max(prev1[0] - arr[ind] , prev1[1] - 0);
                }
                else{
                    profit = max(prev2[1] + arr[ind] , prev1[0] + 0);
                }
                cur[buy] = profit;
            }
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1[1];
    }
};