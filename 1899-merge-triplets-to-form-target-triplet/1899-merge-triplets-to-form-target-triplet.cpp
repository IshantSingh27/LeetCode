class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& arr, vector<int>& tar) {
        int n = arr.size() , a = 0 , b = 0 , c = 0;

        for(int i=0 ; i<n ; i++){
            if(arr[i][0] > tar[0] || arr[i][1] > tar[1] || arr[i][2] > tar[2]) continue;

            if(arr[i][0] == tar[0]) a = 1;
            if(arr[i][1] == tar[1]) b = 1;
            if(arr[i][2] == tar[2]) c = 1;

            if(a && b && c) return true;
        }

        return a && b && c;
    }
};