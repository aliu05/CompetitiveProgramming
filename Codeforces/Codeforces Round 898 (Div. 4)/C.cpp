#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

string a[10];
int s[10][10], ans;

void precompute() {
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j)
            s[i][j] = min(9 - i, min(9 - j, min(i, j))) + 1;
    }
}

void solve() {
    ans = 0;
    for(int i = 0; i < 10; ++i)
        cin >> a[i];
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(a[i][j] == 'X')
                ans += s[i][j];
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    precompute();
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}

//abc, acb, bac, cba
