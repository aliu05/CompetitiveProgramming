#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

#define nl '\n'
#define pb push_back
#define mp make_pair
#define YES "YES\n"
#define NO "NO\n"
#define F0R(a, b) for(i64 (a)=0; (a)<(b); ++(a))
#define F1R(a, b) for(i64 (a)=1; (a)<=(b); ++(a))
#define FORE(a) for(auto& e : (a))
#define all(x) (x).begin(), (x).end()
#define sz(x) (i64)(x).size()

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

template<class T> void read(T& x) {
    cin >> x;
}

template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}

template<class T> void read(vector<T>& v) {
    for(auto &x : v) read(x);
}

template<class T, size_t S> void read(array<T, S>& a) {
    for(auto &x : a) read(x);
}

// Write functions
string to_string(const string& s) {
    return s;
}

string to_string(const char* s) { // overload for const char*
    return string(s);
}

string to_string(char c) {
    return string(1, c);
}

string to_string(bool b) {
    return b ? "true" : "false";
}

template<class T> string to_string(T v) {
    bool first = true;
    string res;
    for(auto &x : v) {
        if(!first) res += ' ';
        first = false;
        res += to_string(x);
    }
    return res;
}

template<class A> void write(A x) {
    cout << to_string(x);
}

template<class H, class... T> void write(const H& h, const T&... t) { 
    write(h);
    write(t...);
}

void print() {
    write("\n");
}

template<class H, class... T> void print(const H& h, const T&... t) { 
    write(h);
    if(sizeof...(t)) write(' ');
    print(t...);
}

// Returns the first index in [lb, rb) for which f(index) is true
i64 FIRSTTRUE(function<bool(i64)> f, i64 lb, i64 rb) {
    while(lb < rb) {
        i64 mb = lb + (rb - lb) / 2;
        if(f(mb)) rb = mb;
        else lb = mb + 1;
    }
    return lb;
}

// Returns the last index in [lb, rb] for which f(index) is true
i64 LASTTRUE(function<bool(i64)> f, i64 lb, i64 rb) {
    while(lb < rb) {
        i64 mb = lb + (rb - lb + 1) / 2;
        if(f(mb)) lb = mb;
        else rb = mb - 1;
    }
    return lb;
}

// ---------------------------- End of Template ----------------------------

void run_case() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; read(t);
    while(t--) run_case();
    return 0;
}
