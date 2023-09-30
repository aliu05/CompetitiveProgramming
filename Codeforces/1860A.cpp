#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

string s;

string f1(int n) {
    string ret = "";
    for(int i = 0; i < n; ++i)
        ret += "()";
    return ret;
}

string f2(int n) {
    string ret = "";
    for(int i = 0; i < n; ++i)
        ret += '(';
    for(int i = 0; i < n; ++i)
        ret += ')';
    return ret;
}

void solve() {
    cin >> s;
    int n = s.length();
    if(n == 1 || s == "()") {
        cout << "NO" << nl;
        return;
    }
    if(s == ")(") {
        cout << "YES" << nl << "(())" << nl;
        return;
    }
    for(int i = 1; i < n - 1; ++i) {
        if(s[i - 1] == '(' && s[i] == ')') {
            if(s[i + 1] == ')') {
                cout << "YES" << nl << f1(n) << nl;
                return;
            }
            else {
                cout << "YES" << nl << f2(n) << nl;
                return;
            }
        }
    }
    for(int i = 1; i < n - 1; ++i) {
        if(s[i] == '(' && s[i + 1] == ')') {
            if(s[i - 1] == '(') {
                cout << "YES" << nl << f1(n) << nl;
                return;
            }
            else {
                cout << "YES" << nl << f2(n) << nl;
                return;
            }
        }
    }
    
    cout << "YES" << nl << f1(n) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}
// list impossible cases
// l1 -> (, )
// l2 -> ()
// l3 -> all possible
// l4 -> all possible

// n = 3; ()( -> ((())); ()) -> ()()(); ))) -> ()()(); )() -> ()()()
