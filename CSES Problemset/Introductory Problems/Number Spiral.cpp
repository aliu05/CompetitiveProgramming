#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 t; cin >> t;
    while(t--) {
        i64 y, x;
        cin >> y >> x;
        i64 layer = max(x, y);
        cout << (layer * layer - layer + (layer & 1? x - y : y - x) + 1) << "\n";
    }
    return 0;
}