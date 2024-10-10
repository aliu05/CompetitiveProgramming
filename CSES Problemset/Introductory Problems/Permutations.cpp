#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n;
    cin >> n;

    if (n == 1) cout << "1";
    else if (n < 4) cout << "NO SOLUTION";
    else {
        for (i64 i = 2; i <= n; i += 2) cout << i << " ";
        for (i64 i = 1; i <= n; i += 2) cout << i << " ";
    }
    return 0;
}