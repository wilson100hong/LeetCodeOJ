class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        
        for (int i=2;i*i<n;++i) {
            if (!primes[i]) continue;
            for (int j=i*i;j<n;j+=i) {
                primes[j] = false;
            }
        }
        
        
        int cnt = 0;
        for (bool p : primes) {
            if (p) cnt++;
        }
        
        return cnt;
    }
};
