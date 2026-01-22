class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size() , k = -1;
        for(int i=0 ; i<n ; i++){
            if(arr[i] == 0){
                if(k == -1) k = i;
                else continue;
            }
            else{
                if(k != -1){
                    swap(arr[k] , arr[i]);
                    if(i - 1 == k){
                        k = i;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
    }
};