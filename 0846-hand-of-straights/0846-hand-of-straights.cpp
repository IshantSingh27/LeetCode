class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        if(arr.size() % k != 0) return false;

        map<int , int> mp;
        for(auto it : arr){
            mp[it]++;
        }

        while(!mp.empty()){
            int start = mp.begin()->first;

            for(int i=start ; i<start + k ; i++){
                if(mp.find(i) == mp.end()) return false;

                mp[i]--;

                if(mp[i] == 0) mp.erase(i);
            }
        }

        return true;
    }
};