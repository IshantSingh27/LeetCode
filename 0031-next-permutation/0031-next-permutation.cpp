class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size() , ind = -1;
        for(int i=n - 1 ; i>0 ; i--){
            if(arr[i] > arr[i - 1]){
                ind = i - 1;
                break;
            }
        }
        if(ind == -1){
            reverse(arr.begin() , arr.end());
            return;
        }
        for(int i=n - 1 ; i>=0 ; i--){
            if(arr[i] > arr[ind]){
                swap(arr[i] , arr[ind]);
                break;
            }
        }
        reverse(arr.begin() + ind + 1 , arr.end());
        return;
    }
};