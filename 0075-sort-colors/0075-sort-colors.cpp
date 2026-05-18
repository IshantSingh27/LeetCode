class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size() , l = 0 , r = n - 1 , i = 0;

        while(i <= r){
            // cout<<"arr[i] : "<<arr[i]<<" | ";
            if(arr[i] == 0){
                // cout<<"here 1 ";
                swap(arr[i] , arr[l]);
                l++;
                i++;
            }
            else if(arr[i] == 2){
                swap(arr[i] , arr[r]);
                r--;
            }
            else i++;

        //     for(int j=0 ; j<n ; j++){
        //     cout<<arr[j]<<" ";
        // }
        // cout<<endl;
        }
    }
};