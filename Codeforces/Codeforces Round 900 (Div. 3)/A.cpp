#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxN = 100;
int n, k, a[mxN];

void run_case() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
        
    bool flag = false;
    for(int i = 0; i < n; ++i) {
        if(a[i] == k)
            flag = true;
    }
    
    cout << (flag? "yes" : "no") << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
