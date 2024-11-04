/*
    Disjoint set / union find with merge by size and path compression
    Updated: 11-04-2024
    Verification: https://cses.fi/problemset/task/1676
*/

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