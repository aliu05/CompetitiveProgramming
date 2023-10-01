#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

double n, k, x;

void run_case() {
    cin >> n >> k >> x;
    double mi, ma;
    mi = (k / 2) * (k + 1);
    ma = (k / 2) * (n + (n - k + 1));
    
    //cout << mi << ':' << ma << nl;
    cout << ((x >= mi && x <= ma)? "yes" : "no") << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
