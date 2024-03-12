/*
    Updated: 03-11-2024
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
    map<int64_t, int64_t> primeFactorMap(int64_t x) {
        map<int64_t, int64_t> ret;
        int64_t tx = x;
        for(int64_t e : primeFactor(x)) {
            while(tx % e == 0)  {
                tx /= e;
                ret[e]++;
            }
        }
        return ret;
    }

    // GCD between 2 elements
    int64_t GCD(int64_t n1, int64_t n2) {
        if(n1 == 0) return n2;
        return GCD(n2 % n1, n1);
    }

    // GCD of integer array (size > 0)
    int64_t arrayGCD(vector<int64_t> vec) {
        if((int)vec.size() == 0) return -1;
        int64_t res = vec[0];
        for(int i = 1; i < (int)vec.size(); ++i) {
            res = GCD(vec[i], res);
            if(res == 1) return 1;
        }
        return res;
    }
}

using namespace lzk_NumberTheory;
