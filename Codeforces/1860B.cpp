#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

int m, k, a1, ak;

void run_case() {
    cin >> m >> k >> a1 >> ak;
    int ans = 0;
    
    int ks = m / k;
    int os = m % k;
    // spend as much ak on k and a1 on m; no negative ks, 1s
    int temp = min(ak, ks);
    ks -= temp;
    ak -= temp;
    temp = min(a1, os);
    os -= temp;
    a1 -= temp;
    
    ans += os; // 1s must be positive and all req fancy 1 coins at this point
    ans += max(ks - (a1 / k), 0); // (a1 / k) is amount of ks that can be made using remaining a1
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
