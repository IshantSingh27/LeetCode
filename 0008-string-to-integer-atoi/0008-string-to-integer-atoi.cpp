class Solution {
public:
    void solve(long long i , string& s , long long &num){
        if(i >= s.size()) return;

        if(s[i] < '0' || s[i] > '9') return;

        num = (num * 10) + (s[i] - '0');

        if(num > (long long)INT_MAX + 1){
            return;
        }

        solve(i + 1 , s , num);
    }

    int myAtoi(string s) {
        long long n = s.size() , i = 0 , sign = 1 , ans = 0;
        while(i < n){
            if(s[i] == ' ') i++;
            else break;
        }
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        while(i < n && s[i] == '0') i++;

        solve(i , s , ans);

        ans = ans * sign;

        if(ans > INT_MAX) return INT_MAX;
        else if(ans < INT_MIN) return INT_MIN;

        return ans;
    }
};