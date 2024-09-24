#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

#define nl '\n'
#define pb push_back
#define mp make_pair
#define YES "YES\n"
#define NO "NO\n"
#define F0R(a, b) for(i64 (a)=0; (a)<(b); ++(a))
#define FORE(a) for(auto& e : (a))
#define all(x) (x).begin(), (x).end()
#define sz(x) (i64)(x).size()

// source: neal cf blog
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    } 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void run_case(i64 caseNum, ifstream& cin, ofstream& cout) {
    
    cout << "Case #" << caseNum << ": ";
}

int main() {
    ifstream cin("hackercup.in");
    ofstream cout("hackercup.out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    F0R(i, t) run_case(i + 1, cin, cout);
    return 0;
}