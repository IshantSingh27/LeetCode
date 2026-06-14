class Solution {
public:
    double sol(double x, long long n){
        if(n == 0) return 1;

        double half = sol(x , n / 2);

        if(n % 2 == 1) return half * half * x;
        else return half * half;
    }
    double myPow(double x, int n) {
        if(x == 1) return 1;
        long long p = n;
        if(n < 0){
            x = 1 / x;
            p = (long long)(-1) * p;
        }
        
        return sol(x , p);
    }
};