class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256 , -1);
        int l = 0 , r = 0 , ans = 0;

        for(int i=0 ; i<s.size() ; i++){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l) l = hash[s[r]] + 1;
            }

            ans = max(ans , r - l + 1);
            hash[s[r]] = r;
            r++;
        }

        return ans;
    }
};