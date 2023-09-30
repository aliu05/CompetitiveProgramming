#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int n, k, ans;
string s;

void solve() {
    cin >> n >> k >> s;
    ans = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'B') {
            ++ans;
            i += k - 1;
        }
    }
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

//abc, acb, bac, cba
