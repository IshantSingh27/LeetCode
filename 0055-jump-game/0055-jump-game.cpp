class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size() , i = 0;
        while(i < n){
            int jump = 0 , j = arr[i] , ind = 0;

            // cout<<"j : "<<j<<endl;

            if(i + j >= n - 1) return true;

            for(int k=1 ; k<=j ; k++){
                // cout<<"arr[i + k] : "<<arr[i + k]<<endl;
                if(arr[i + k] + i + k >= jump){
                    jump = arr[i + k] + i + k;
                    ind = i + k;
                    // cout<<"k : "<<k<<" jump : "<<jump<<endl;
                }
            }

            // cout<<"JUMP : "<<jump<<endl;

            if(ind == 0) return false;

            i = ind;
        }

        return false;
    }
};