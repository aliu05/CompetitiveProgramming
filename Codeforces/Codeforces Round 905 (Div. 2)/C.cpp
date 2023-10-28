#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back
#define mp make_pair

const int mxN = 1e5;

void run_case() {
    int n, a[mxN + 5], suf[mxN + 5];
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    set<int> seen;
    seen.insert(a[n - 1]);
    suf[n - 1] = 1;
    for(int i = n - 2; i >=0; --i) {
        suf[i] = suf[i + 1];
        if(!seen.count(a[i])) {
            suf[i]++;
            seen.insert(a[i]);
        }
    }
    seen.clear();
    int64_t ans = 0;
    for(int i = 0; i < n; ++i) {
        if(!seen.count(a[i])) {
            ans += suf[i];
            seen.insert(a[i]);
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
