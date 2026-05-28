class Solution {
public:
    double sol(double x , int n){
        if(n == 0) return 1;

        double half = sol(x , n / 2);

        if(n % 2 == 0) return half * half;
        else return half * half * x;
    }
    double myPow(double x, int n) {
        if(n < 0){
            x = 1 / x;
            n = (long long)(-1) * n;
        }
        if(x == 1) return 1;
        return sol(x , n);
    }
};