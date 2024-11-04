#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

struct DSU {
    vector<i64> rep, size;
    DSU(i64 n) {
        rep = vector<i64>(n);
        size = vector<i64>(n, 1);
        for(i64 i = 0; i < n; ++i) rep[i] = i;
    }

    i64 getRep(i64 x) { return (rep[x] == x? x : rep[x] = getRep(rep[x])); }
    bool sameSet(i64 x, i64 y) { return getRep(x) == getRep(y); }
    i64 getSize(i64 x) { return size[getRep(x)]; }

    void unite(i64 x, i64 y) {
        x = getRep(x);
        y = getRep(y);
        if(x != y) {
            if(size[x] < size[y]) swap(x, y);
            rep[y] = x;
            size[x] += size[y];
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n, m; cin >> n >> m;
    DSU dsu(n);
    i64 components = n, largest = 1;
    while(m--) {
        i64 u, v; cin >> u >> v;
        u--; v--;
        if(!dsu.sameSet(u, v)) {
            largest = max(largest, dsu.getSize(u)+dsu.getSize(v));
            components--;
        }
        dsu.unite(u, v);

        cout << components << ' ' << largest << "\n";
    }
    return 0;
}