class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;
        int n = arr.size();

        for(int i=0 ; i<n ; i++){
            if(i > 0 && arr[i] == arr[i - 1]) continue;
            int j = i + 1 , k = n - 1 , sum = arr[i];

            while(j < k){
                int cur = arr[j] + arr[k];

                if(cur + sum < 0){
                    j++;
                }
                else if(cur + sum > 0){
                    k--;
                }
                else{
                    ans.push_back({arr[i] , arr[j] , arr[k]});
                    j++;
                    k--;
                    while(j < k && arr[j] == arr[j - 1]) j++;
                    while(k > j && arr[k] == arr[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};