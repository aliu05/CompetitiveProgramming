#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for(i64& ie : a) cin >> ie;

    i64 ans = 0, cur = a[0];
    for(i64 i = 1; i < n; ++i) {
        ans += min((i64)0, cur - a[i]);
        cur = min(cur, a[i]);
    }
    cout << ans;
    return 0;
}