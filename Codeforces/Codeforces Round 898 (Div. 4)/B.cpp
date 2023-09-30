#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int n;

void run_case() {
    cin >> n;
    int last = 1;
    for(int i = 0; i < n; ++i) {
        cout << last << ' ';
        last += 2;
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
