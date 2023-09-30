#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

string s;

void solve() {
    cin >> s;
    if(s == "abc" || s == "acb" || s == "bac" || s == "cba")
        cout << "YES" << nl;
    else
        cout << "NO" << nl;
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
