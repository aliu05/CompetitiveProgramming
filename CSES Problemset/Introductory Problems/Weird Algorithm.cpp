#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n;
    cin >> n;
    while(n != 1) {
        cout << n << " ";
        if(n & 1) n = 3 * n + 1;
        else n /= 2;
    }
    cout << 1;
    return 0;
}