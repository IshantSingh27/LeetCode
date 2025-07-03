class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size() , jump = 0 , end = 0 , maxi = 0;

        for(int i=0 ; i<n-1 ; i++){
            maxi = max(maxi , i + arr[i]);

            if(i == end){
                jump++;
                end = maxi;
            }
        }

        return jump;
    }
};