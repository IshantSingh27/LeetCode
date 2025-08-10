class Solution {
public:
    int sortPermutation(vector<int>& arr) {
        int n = arr.size();
        int k = INT_MAX;
        for(int i=0 ; i<n ; i++){
            if(arr[i] != i){
                k = k & arr[i];
            }
        }
        if(k == INT_MAX) return 0;
        return k;
    }
};