class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        if(k > arr.size()) k = k % arr.size();
        reverse(arr.begin() , arr.end());
        reverse(arr.begin() , arr.begin() + k);
        reverse(arr.begin() + k , arr.end());
    }
};