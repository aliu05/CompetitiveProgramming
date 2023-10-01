#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int64_t a;

void run_case() {
    cin >> a;
    if(a == 0)
        cout << 1 << nl;
    else
        cout << fixed << setprecision(0) << pow(2, __builtin_popcount(a)) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
