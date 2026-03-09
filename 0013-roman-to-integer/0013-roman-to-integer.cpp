class Solution {
public:
    int romanToInt(string s) {
        int ans = 0 , n = s.size();
        unordered_map<char , int> mp;
        mp['I'] = 1; mp['V'] = 5; mp['X'] = 10; mp['L'] = 50;
        mp['C'] = 100; mp['D'] = 500; mp['M'] = 1000; 
    
        int i = 0;
        while(i < n - 1){
                if(mp[s[i]] < mp[s[i + 1]]){
                    ans = ans + (mp[s[i + 1]] - mp[s[i]]);
                    i++;
                }
                else ans = ans + mp[s[i]];

                i++;
                cout<<"ans : "<<ans<<endl;
        }
                cout<<"ans : "<<ans<<endl;

                if(i == n -1) ans = ans + mp[s[n - 1]]; 

                return ans;
        }
};