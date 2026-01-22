class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size() , maxi = 0;
        bool once = true;

        for(int i=1 ; i<n ; i++){
            if(arr[i] == arr[i - 1]) continue;
            if(arr[i] > arr[i - 1]){
                cout<<"idhr : ";
                if(!once){
                    if(arr[i] > maxi) return false;
                }
            }
            else{
                cout<<"udhr : ";
                if(!once){
                    return false;
                }
                maxi = arr[0];
                if(arr[i] > maxi) return false;
                once = false;
            }
        }

        return true;
    }
};