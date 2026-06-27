class Solution {
public:
    int trap(vector<int>& arr) {
        int l = 0 , r = arr.size() - 1 , lmax = 0 , rmax = 0 , tot = 0;
        while(l < r){
            if(arr[l] <= arr[r]){
                if(arr[l] < lmax){
                    tot += lmax - arr[l];
                }
                else lmax = arr[l];
                l++;
            }
            else{
                if(arr[r] < rmax){
                    tot += rmax - arr[r];
                }
                else rmax = arr[r];
                r--;
            }
        }
        return tot;
    }
};