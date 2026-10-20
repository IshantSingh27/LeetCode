class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size() , i = 0 , cnt = 0;
        if(arr[0] == 0 || n == 1) return 0;

        while(i < n){
            cnt++;
            if(i + arr[i] >= n - 1) return cnt;
            // cout<<arr[i]<<endl;

            int jump = 0 , fin = i + 1 , j = i + 1;
            while(j <= i + arr[i]){
                if(j + arr[j] >= jump){
                    fin = j;
                    jump = j + arr[j];
                }
                j++;
            }

            i = fin;
        }

        return cnt;
    }
};