class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans(n);

        for(int i=0 ; i<n ; i++){
            ans[(i + k) % n] = arr[i];
        }

        for(int i=0 ; i<n ; i++){
            arr[i] = ans[i];
        }
    }
};