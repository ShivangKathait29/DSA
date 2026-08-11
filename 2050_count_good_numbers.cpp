class Solution {
public:
    const int MOD = 1e9 + 7;
    long long rec(long long base,long long power){
        long long result = 1;
        base %= MOD;
        while(power>0){
            if(power%2==1){
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            power /=2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long e = (n+1)/2;
        long long o = n/2;
        long long evenWays = rec(5,e);
        long long oddWays = rec(4,o);
        return (evenWays * oddWays) % MOD;
    }
};