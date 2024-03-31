/*
    Updated: 03-11-2024
    Status:  Incomplete
    Source:  me
*/

namespace lzk_NumberTheory {
    // Prime sieve returns all primes up to (x)
    vector<i64> sieve(i64 x) {
        vector<bool> prm(x + 1, true);
        for(int i = 2; i * i <= x; ++i) {
            if(prm[i]) {
                for(int j = i * i; j <= x; j += i) {
                    prm[j] = false;
                }
            }
        }
        vector<i64> ret;
        for(int i = 2; i <= x; ++i) {
            if(prm[i]) ret.pb(i);
        }
        return ret;
    }
    
    // Creates a vector of prime factors of (x)
    vector<i64> primeFactor(i64 x) {
        vector<i64> ret;
        for(i64 e : sieve(x)) {
            if(x % e == 0) ret.pb(e);
        }
        return ret;
    }
    
    // Counts the exponent of each prime factor
    map<i64, i64> primeFactorMap(i64 x) {
        map<i64, i64> ret;
        i64 tx = x;
        for(i64 e : primeFactor(x)) {
            while(tx % e == 0)  {
                tx /= e;
                ret[e]++;
            }
        }
        return ret;
    }

    // Sorted factors of a number (x > 1)
    vector<i64> factor(i64 x) {
    	i64 tsize = 0;
		for(i64 i = 1; i * i <= x; ++i) {
			if(x % i == 0) tsize++;
		}
		tsize *= 2;
		if(ceil((double)sqrt(x)) == floor((double)sqrt(x))) tsize--;
		vector<i64> ret(tsize);
		i64 tii = 0;
		for(i64 i = 1; i * i <= x; ++i) {
			if(x % i == 0) {
				ret[tii] = i;
				ret[tsize - tii - 1] = x / i;
				tii++;
			}
		}
		return ret;
	}

    // GCD between 2 elements
    i64 GCD(i64 n1, i64 n2) {
        if(n1 == 0) return n2;
        return GCD(n2 % n1, n1);
    }

    // GCD of integer array (size > 0)
    i64 arrayGCD(vector<i64> vec) {
        if((int)vec.size() == 0) return -1;
        i64 res = vec[0];
        for(int i = 1; i < (int)vec.size(); ++i) {
            res = GCD(vec[i], res);
            if(res == 1) return 1;
        }
        return res;
    }
}

using namespace lzk_NumberTheory;
