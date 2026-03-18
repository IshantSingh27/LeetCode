class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size() , l = 0 , r = n - 1 , lmax = 0 , rmax = 0 , tot = 0;

        while(l < r){
            if(arr[l] <= arr[r]){
                if(lmax >= arr[l]){
                    tot += lmax - arr[l];
                }
                else lmax = arr[l];
                l++;
            }
            else{
                if(rmax >= arr[r]){
                    tot += rmax - arr[r];
                }
                else rmax = arr[r];
                r--;
            }
        }

        return tot;
    }
};