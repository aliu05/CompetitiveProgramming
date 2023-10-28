#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

const int mxN = 1e5;
int n;
string s;

void run_case() {
    cin >> n >> s;
    
    int must1, can2;
    must1 = can2 = 0;
    for(int i = 0; i < n / 2; ++i) {
        if(s[i] == s[n - 1 - i])
            can2++;
        else
            must1++;
    }
    
    if(n % 2) {
        for(int i = 0; i <= n; ++i) {
            if(i < must1)
                cout << 0;
            else if(i - must1 <= 2 * can2 + 1)
                cout << 1;
            else
                cout << 0;
        }
    }
    else {
        for(int i = 0; i <= n; ++i) {
            if(i < must1)
                cout << 0;
            else if((i - must1) % 2 == 0 && (i - must1) <= 2 * can2)
                cout << 1;
            else
                cout << 0;
        }
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
