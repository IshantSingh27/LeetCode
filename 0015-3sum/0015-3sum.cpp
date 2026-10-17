class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin() , arr.end());

        for(int i=0 ; i<n - 2 ; i++){
            if(i > 0 && arr[i] == arr[i - 1]) continue;

            int j = i + 1 , k = n - 1 , sum = arr[i];
            while(j < k){
                if(sum + arr[j] + arr[k] == 0){
                    ans.push_back({arr[i] , arr[j] , arr[k]});
                    j++;
                    while(j < n && arr[j] == arr[j - 1]) j++;
                    k--;
                    while(k > i && arr[k] == arr[k + 1]) k--;
                }
                else if(sum + arr[j] + arr[k] < 0) j++;
                else k--;
            } 
        }

        return ans;
    }
};