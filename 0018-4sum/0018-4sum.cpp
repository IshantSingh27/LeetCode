class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int tar) {
        long long n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin() , arr.end());

        for(long long i=0 ; i<n ; i++){
            if(i > 0 && arr[i] == arr[i - 1]) continue;

            for(long long j = i + 1 ; j<n ; j++){
                if(j > i + 1 && arr[j] == arr[j - 1]) continue;

                long long k = j + 1 , l = n - 1;
                while(k < l){
                    long long sum = arr[i];
                    sum += arr[j]; sum += arr[k]; sum += arr[l];

                    if(sum == tar){
                        ans.push_back({arr[i] , arr[j] , arr[k] , arr[l]});
                        k++;
                        l--;
                        while(k < l && arr[k] == arr[k - 1]) k++;
                        while(l > k && arr[l] == arr[l + 1]) l--;
                    }
                    else if(sum > tar) l--;
                    else k++;
                }
            }
        }

        return ans;
    }
};