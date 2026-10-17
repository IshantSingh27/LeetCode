class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size() , m = s2.size() , l = 0;
        unordered_map<char , int> mp1 , mp2;

        for(int i=0 ; i<n ; i++){
            mp1[s1[i]]++;
        }

        for(int i=0 ; i<m ; i++){
            if(i < n - 1) {
                mp2[s2[i]]++;
            }
            else{
                mp2[s2[i]]++;
                if(i - l + 1 > n){
                    mp2[s2[l]]--;
                    l++;
                }

                bool pos = true;
                for(int j=0 ; j<n ; j++){
                    if(mp1[s1[j]] != mp2[s1[j]]){
                        pos = false;
                        break;
                    }
                }
                if(pos) return true;
            }
        }

        return false;
    }
};