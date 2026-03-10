class Solution {
public:
    int myAtoi(string s) {
        int i = 0 , sign = 1;
        while(s[i] == ' ') i++;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+') i++;
        cout<<"i : "<<i<<endl;

        long long ans = 0;

        while(s[i] <= '9' && s[i] >= '0'){
            ans = ans * 10 + (s[i] - '0');
            if(ans > INT_MAX || ans < INT_MIN){
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            i++;
        }

        return ans * sign;
    }
};