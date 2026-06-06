class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini =arr[0] , ans = 0;
        for(int i=1 ; i<arr.size() ; i++){
            ans = max(ans , arr[i] - mini);
            mini = min(mini , arr[i]);
        }
        return ans;
    }
};