class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size() , cnt = 0 , j = 0;
        sort(arr.begin() , arr.end());
        for(int i=1 ; i<n ; i++){
            if(arr[i][0] < arr[j][1]){
                cnt++;
                if(arr[i][1] < arr[j][1]) j = i;
            }
            else{
                j = i;
            }
        }
        return cnt;
    }
};