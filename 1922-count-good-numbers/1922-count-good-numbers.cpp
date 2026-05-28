class Solution {
public:
int mod = 1e9 + 7;
    long long pow(long long a , long long n){
        if(n == 0) return 1;

        long long half = pow(a , n / 2);

        if(n % 2 == 0) return (half * half) % mod;
        else return (half * half * a) % mod;
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (pow(5 , even) * pow(4 , odd) ) % mod;
    }
};