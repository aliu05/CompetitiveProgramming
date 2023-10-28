#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back
#define mp make_pair

const int mxN = 2e5;
int n, k, r[mxN + 5];

void run_case() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> r[i];
    if(k != 4) {
        int mr = 6;
        for(int i = 0; i < n; ++i) {
            if(r[i] % k == 0)
                mr = 0;
            else if(k - r[i] % k < mr)
                mr = k - r[i] % k;
        }
        cout << mr << nl;
    }
    else { // k=4; make 2 even -> can div
        int ec = 0;
        bool m4 = false;
        for(int i = 0; i < n; ++i) {
            if(r[i] % 4 == 0)
                m4 = true;
            if(!(r[i] & 1))
                ec++;
        }
        if(m4 || ec >= 2) {
            cout << 0 << nl;
            return;
        }
        // no div by 4, either make div by 4 or make 2 even nums
        // ans = 1 or 2
        for(int i = 0; i < n; ++i) {
            if((r[i] + 1) % 4 == 0) {
                cout << 1 << nl;
                return;
            }
            if(r[i] & 1 && ec) {
                cout << 1 << nl;
                return;
            }
        }
        cout << 2 << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
