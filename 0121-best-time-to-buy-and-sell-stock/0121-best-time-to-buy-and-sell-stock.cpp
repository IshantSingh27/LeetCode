class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit = 0 , n = arr.size() , mini = arr[0];
        if(n == 1) return 0;

        for(int i=1 ; i<n ; i++){
            mini = min(mini , arr[i-1]);
            profit = max(profit , arr[i] - mini);
        }

        return profit;
    }
};