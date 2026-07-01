class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size() , i = 0 , k = 0 , j = n - 1;
        while(k <= j){
            if(arr[k] == 0){
                swap(arr[k] , arr[i]);
                i++;
                k++;
            }
            else if(arr[k] == 2){
                swap(arr[j] , arr[k]);
                j--;
            }
            else{
                k++;
            }
        }
    }
};