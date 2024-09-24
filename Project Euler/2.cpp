#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int f1, f2, ans;
    f1 = 1;
    f2 = 2;
    
    ans = 2;
    while(f1 + f2 <= 4e6) {
        int t = f1 + f2;
        f1 = f2;
        f2 = t;
        if(t % 2 == 0)
            ans += t;
    }
    cout << ans;
    return 0;
}
