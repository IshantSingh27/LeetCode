class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        map<int , int> mp;
        int n = arr.size();
        if(n % k != 0){
            return false;
        }

        for(int i=0 ; i<n ; i++){
            mp[arr[i]]++;
        }

        while(!mp.empty()){
            int num = mp.begin()->first;

            for(int i=num ; i<num + k ; i++){
                if(mp.find(i) == mp.end()) return false;

                mp[i]--;
                if(mp[i] == 0) mp.erase(i);
            }
        }

        return true;
    }
};