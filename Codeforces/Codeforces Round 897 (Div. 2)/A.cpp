#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

const int mxN = 4e4;
int n, ans[mxN + 1];
pair<int, int> a[mxN + 1];

void run_case() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    
    for(int i = 0; i < n; ++i)
        ans[a[i].second] = n - i;
    
    for(int i = 0; i < n; ++i)
        cout << ans[i] << " ";
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
