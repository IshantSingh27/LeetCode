class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size() , k = 0;
        for(int i=0 ; i<n ; i++){
            if(arr[i] != 0){
                arr[k] = arr[i];
                k++;
            }
        }
        for(int i=k ; i<n ; i++){
            arr[i] = 0;
        }
    }
};