class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        bool once = true;

        for(int i=1 ; i<n ; i++){
            if(arr[i] < arr[i - 1]){
                if(!once){
                    return false;
                }
                once = false;
            }
        }
        if(!once && arr[n - 1] > arr[0]) return false;

        return true;
    }
};