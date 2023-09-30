#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int n, a[10], mx, ans;

void solve() {
    cin >> n;
    ans = 1;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    ++a[0];
    for(int i = 0; i < n; ++i)
        ans *= a[i];
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}
