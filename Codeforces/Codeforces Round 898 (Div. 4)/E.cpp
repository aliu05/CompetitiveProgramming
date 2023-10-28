#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

const int mxN = 2e5;
int64_t n, x, a[mxN + 5];
int64_t ans;

void run_case() {
    cin >> n >> x;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int64_t ti = 1;
    ans = 0;
    while(ti < n && x >= ti * (a[ti] - a[ti - 1])) {
        x -= ti * (a[ti] - a[ti - 1]);
        ans = a[ti];
        ti++;
    }
    if(ti == 1)
        ans = a[0] + x;
    else
        ans += x / ti;
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
