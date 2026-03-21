class Solution {
public:
    int solve(string& s , int i , long long& num , int sign){
        if(i > s.size() || s[i] < '0' || s[i] > '9') return sign * num;

        int digit = s[i] - '0';

        if(num > (INT_MAX - digit) / 10){
            if(sign == -1) return INT_MIN;
            else return INT_MAX;
        }

        num = num * 10 + digit;

        return solve(s , i + 1 , num , sign);
    }

    int myAtoi(string s) {
        int i = 0 , sign = 1;
        while(s[i] == ' '){
            i++;
        }
        if(i < s.size() && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        long long num = 0;

        return solve(s , i , num , sign);
    }
};