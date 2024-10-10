/*
    https://codeforces.com/contest/1915/problem/F
*/

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

struct lzk_segtree {
    i64 N;
    vector<i64> tree;
    lzk_segtree(vector<i64> vi) {
        N = sz(vi);
        tree.resize(2 * N);
        for(i64 i = N; i < 2 * N; ++i) tree[i] = vi[i - N];
        for(i64 i = N - 1; i > 0; --i)  {
            // This determines what ranges are!
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    
    void update(i64 ind, i64 val) {
        for(i64 i = N + ind; i > 0; i /= 2) tree[i] += val;
    }

    // Inclusive range [l, r]
    i64 query(i64 l, i64 r) {
        i64 ret = 0;
        for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
            if(l % 2) ret += tree[l++];
            if(r % 2) ret += tree[--r];
        }
        return ret;
    }
};

void run_case() {
    i64 n;
    cin >> n;
    vector<pair<i64, i64> > p(n);
    F0R(i, n) cin >> p[i].first >> p[i].second;
    
    // map sorted coords -> [0, 2n-1]
    vector<i64> supervec;
    FORE(p) {
        supervec.pb(e.first);
        supervec.pb(e.second);
    }
    sort(all(supervec));
    map<i64, i64> cmap;
    F0R(i, 2 * n) cmap.insert(mp(supervec[i], i));
    vector<pair<i64, i64> > compr(n);
    F0R(i, n) {
        compr[i].first = cmap[p[i].first];
        compr[i].second = cmap[p[i].second];
    }
    sort(all(compr));
    reverse(all(compr));

    // segtree to track number of people ending (b-point) in all ranges
    // for each person query the number of endings in their range of travel
    lzk_segtree st(vector<i64>(2 * n, 0));

    i64 ans = 0;
    FORE(compr) {
        ans += st.query(e.first, e.second);
        st.update(e.second, 1);
    }
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) run_case();
    return 0;
}
