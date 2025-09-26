class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size() , mini = arr[0] , profit = 0;

        for(int i=1 ; i<n ; i++){
            profit = max(profit , arr[i] - mini);
            mini = min(mini , arr[i]);
        }

        return profit;
    }
};