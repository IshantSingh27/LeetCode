class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin() , g.rend());
        sort(s.rbegin() , s.rend());

        int n = g.size() , m = s.size() , cnt = 0 , i = 0 , j = 0;
        while(i < n && j < m){
            if(s[j] >= g[i]){
                cnt++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return cnt;
    }
};