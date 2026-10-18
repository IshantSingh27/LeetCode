class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26 , 0) , ans;
        int n = s.size();

        for(int i=0 ; i<n ; i++){
            mp[s[i] - 'a'] = i;
        }

        int i = 0;
        while(i < n){
            int j = mp[s[i] - 'a'] , k = i + 1;
            // cout<<"j : "<<j<<endl;
            while(k < n && k <= j){
                j = max(j , mp[s[k] - 'a']);
                k++;
            }
            ans.push_back(j - i + 1);
            i = k;
        }

        return ans;
    }
};