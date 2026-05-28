class Solution {
public:
    void solve(long long i , string& s , long long &ans){
        if(i >= s.size()) return;
        if(s[i] < '0' || s[i] > '9') return;

        ans = (ans * 10) + (s[i] -  '0');

        if(ans > INT_MAX) return;

        solve(i + 1 , s , ans);
    }
    int myAtoi(string s) {
        long long n = s.size() , ans = 0 , i = 0 , sign = 1;
        while(i < n && s[i] == ' ') i++;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+') i++;

        solve(i , s , ans);

        ans *= sign;

        if(ans > INT_MAX) return INT_MAX;
        else if(ans < INT_MIN) return INT_MIN;

        return ans;
    }
};