class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size() , k = 1 , ind = 1;
        for(int i=1 ; i<n ; i++){
            if(arr[i] == arr[i - 1]){
                continue;
            }
            else{
                arr[ind] = arr[i];
                ind++;
                k++;
            }
        }
        return k;
    }
};