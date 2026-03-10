class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;
        long long ans = 0;

        // skip spaces
        while(i < n && s[i] == ' ') i++;

        // sign
        if(i < n && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // digits
        while(i < n && isdigit(s[i])){
            ans = ans * 10 + (s[i] - '0');

            if(sign * ans > INT_MAX) return INT_MAX;
            if(sign * ans < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};