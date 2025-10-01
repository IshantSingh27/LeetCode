class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int i = 0;
        sort(arr.begin() , arr.end());
        while(i < arr[0].size() && arr[0][i] == arr[arr.size() - 1][i]) i++;
        return arr[0].substr(0 , i);
    }
};