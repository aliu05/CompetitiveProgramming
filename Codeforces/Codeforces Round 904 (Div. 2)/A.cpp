#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

int x, k;

void run_case() {
    cin >> x >> k;
    while(true) {
        int xc = x;
        int ds = 0;
        int m;
        while(xc > 0) {
            m = xc % 10;    
            ds += m;    
            xc /= 10; 
        }
        if(ds % k == 0)
            break;
        x++;
    }
    cout << x << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
