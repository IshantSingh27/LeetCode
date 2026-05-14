class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size() , i = 0 , ans = 0;

        if(n == 1) return ans;

        while(i < n){
            int jump = 0 , j = arr[i] , ind = 0;

            ans++;

            if(i + j >= n - 1) return ans;

            for(int k=1 ; k<=j ; k++){
                if(arr[i + k] + i + k >= jump){
                    jump = arr[i + k] + i + k;
                    ind = i + k;
                }
            }

            if(ind == 0) return 0;

            i = ind;
        }

        return 0;
    }
};