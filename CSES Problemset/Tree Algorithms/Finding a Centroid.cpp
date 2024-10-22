#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

i64 dfs(i64 cur, i64 parent, vector<vector<i64>>& adj, i64 n, i64& centroidId) {
    i64 subtreeSize = 1;
    bool isCentroid = true;

    for(i64 child : adj[cur]) {
        if(child == parent) continue;
        i64 size = dfs(child, cur, adj, n, centroidId);
        if(size > n / 2) isCentroid = false;
        subtreeSize += size;
    }

    if (isCentroid && (n - subtreeSize) <= n / 2) centroidId = cur;
    return subtreeSize;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n; cin >> n;
    vector<vector<i64>> adj(n + 1);
    for(i64 i = 0; i < n - 1; ++i) {
        i64 u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    i64 ans = -1;
    bool fnd = false;
    dfs(1, -1, adj, n, ans);
    cout << ans << "\n";
    return 0;
}
