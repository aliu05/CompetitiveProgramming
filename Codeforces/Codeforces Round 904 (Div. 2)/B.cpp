#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

int n;
string b;

void run_case() {
    cin >> n >> b;
    set<int> open;
    for(int i = 0; i < n; ++i) {
        if(b[i] == '0')
            open.insert(i);
    }
    int64_t ans = 0;
    bool flag = false;
    for(int i = n - 1; i >= 0; --i) {
        if(flag) {
            cout << -1 << " ";
            continue;
        }
        else if(!open.count(i)) {
            if(open.lower_bound(i) == open.begin()) {
                flag = true;
                cout << -1 << " ";
                continue;
            }
            else {
                //swap(b[i], b[ti]);
                ans += i - (*--open.lower_bound(i));
                open.erase(*--open.lower_bound(i));
                cout << ans << " ";
            }
        }
        else
            cout << ans << " ";
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
