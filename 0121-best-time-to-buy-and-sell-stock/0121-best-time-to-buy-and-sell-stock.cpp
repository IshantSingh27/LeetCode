class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini = 1e9 , n = arr.size() , ans = 0;
        for(int i=0 ; i<n ; i++){
            ans = max(ans , arr[i] - mini);

            if(arr[i] < mini) mini = arr[i];
        }

        return ans;
    }
};