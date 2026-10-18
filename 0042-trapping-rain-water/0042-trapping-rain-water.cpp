class Solution {
public:
    int trap(vector<int>& arr) {
        int l = 0 , r = arr.size() - 1 , lmax =  0 , rmax = 0 , ans = 0;

        while(l < r){
            int mini = max(lmax , rmax);

            if(arr[l] <= arr[r]){
                // cout<<"mini : "<<mini<<" arr[l] : "<<arr[l]<<endl;
                if(arr[l] < mini){
                    ans += mini - arr[l];
                    // cout<<"ans : "<<ans<<endl;
                }

                lmax = max(lmax , arr[l]);

                l++;
            }
            else{
                // cout<<"mini : "<<mini<<" arr[r] : "<<arr[r]<<endl;
                if(arr[r] < mini){
                    ans += mini - arr[r];
                    // cout<<"ans : "<<ans<<endl;
                }

                rmax = max(rmax , arr[r]);

                r--;
            }
        }

        return ans;
    }
};