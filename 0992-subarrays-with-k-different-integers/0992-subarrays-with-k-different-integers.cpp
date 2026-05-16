class Solution {
public:
    int sol(vector<int>& arr, int k){
        unordered_map<int , int> mp;
        int l = 0 , cnt = 0;

        for(int i=0 ; i<arr.size() ; i++){
            mp[arr[i]]++;

            while(l < arr.size() && mp.size() > k){
                mp[arr[l]]--;
                if(mp[arr[l]] == 0) mp.erase(arr[l]);
                l++;
            }

            if(mp.size() <= k){
                cnt += i - l + 1;
            }
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return sol(arr , k) - sol(arr , k - 1);
    }
};