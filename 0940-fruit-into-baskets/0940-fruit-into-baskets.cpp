class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;
        int maxlen = 0 , l = 0 , r = 0;
        while(r < n){
            mp[arr[r]]++;
            if(mp.size() > 2){
                mp[arr[l]]--;
                if(mp[arr[l]] == 0){
                    mp.erase(arr[l]);
                }
                l++;
            }
            if(mp.size() <= 2){
                maxlen = max(maxlen , r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};