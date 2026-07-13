class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128 , 0);
        for(char c : s){
            freq[c]++;
        }
        int n = s.size();
        vector<vector<char>> buc(n + 1);
        for(int i=0 ; i<128 ; i++){
            if(freq[i] > 0) buc[freq[i]].push_back(char(i));
        }
        string ans;
        for(int i=n ; i>0 ; i--){
            for(char c : buc[i]){
                ans.append(i , c);
            }
        }
        return ans;
    }
};