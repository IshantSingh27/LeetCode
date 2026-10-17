class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini = arr[0] , n = arr.size() , ans = 0;

        for(int i=1 ; i<n ; i++){
            if(arr[i] > mini){
                ans = max(ans , arr[i] - mini);
            }

            else mini = min(mini , arr[i]);
        }

        return ans;
    }
};