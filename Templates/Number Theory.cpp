/*
    Updated: 03-03-2024
    Status:  Incomplete
    Source:  me
*/

namespace lzk_NumberTheory {
    // Prime sieve returns all primes up to (x)
    vector<int64_t> sieve(int64_t x) {
        vector<bool> prm(x + 1, true);
        for(int i = 2; i * i <= x; ++i) {
            if(prm[i]) {
                for(int j = i * i; j <= x; j += i) {
                    prm[j] = false;
                }
            }
        }
        vector<int64_t> ret;
        for(int i = 2; i <= x; ++i) {
            if(prm[i]) ret.pb(i);
        }
        return ret;
    }
    
    // Creates a vector of prime factors of (x)
    vector<int64_t> primeFactor(int64_t x) {
        vector<int64_t> ret;
        for(int64_t e : sieve(x)) {
            if(x % e == 0) ret.pb(e);
        }
        return ret;
    }
    
    // Counts the exponent of each prime factor
    map<int64_t, int> primeFactorMap(int64_t x) {
        map<int64_t, int> ret;
        int64_t tx = x;
        for(int64_t e : primeFactor(x)) {
            while(tx % e == 0)  {
                tx /= e;
                ret[e]++;
            }
        }
        return ret;
    }
}

using namespace lzk_NumberTheory;
