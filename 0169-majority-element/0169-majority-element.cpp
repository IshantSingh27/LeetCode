class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size() , ele = 0 , cnt = 0;

        for(int i=0 ; i<n ; i++){
            if(cnt == 0){
                cnt++;
                ele = arr[i];
            }
            else if(arr[i] == ele){
                cnt++;
            }
            else cnt--;
        }

        return ele;

        // int ans = 0;
        // for(int i=0 ; i<n ;i++){
        //     if(arr[i] == ele) ans++;
        // }
        // if(ans > n / 2) return ele;
        // else return -1;
    }
};