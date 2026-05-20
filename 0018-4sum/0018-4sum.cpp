class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int tar) {
        long long n = arr.size();
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;

        for(long long i=0 ; i<=n-4 ; i++){
            if(i > 0 && arr[i] == arr[i - 1]) continue;
            long long sum = arr[i];
            for(long long j = i + 1 ; j<=n-3 ; j++){
                if(j > i + 1 && arr[j] == arr[j - 1]) continue;
                long long k = j + 1 , l = n - 1 , cur = sum + arr[j];

                while(k < l){
                    long long temp = arr[k] + arr[l];

                    if(cur + temp > tar){
                        l--;
                    }
                    else if(cur + temp < tar){
                        k++;
                    }
                    else{
                        ans.push_back({arr[i] , arr[j] , arr[k] , arr[l]});
                        k++;
                        l--;
                        while(k < l && arr[k] == arr[k - 1]) k++;
                        while(k < l && arr[l] == arr[l + 1]) l--;
                    }
                }
            }
        }

        return ans;
    }
};