#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

int n;

void run_case() {
    cin >> n;
    if(n <= 6 || n == 9)
        cout << "NO" << nl;
    else if(n % 3)
        cout << "YES" << nl << "1 2 " << n - 3 << nl;
    else
        cout << "YES" << nl << "1 4 " << n - 5 << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
