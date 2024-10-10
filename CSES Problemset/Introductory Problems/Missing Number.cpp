#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n;
    cin >> n;
    vector<bool> seen(n + 1, false);
    for(i64 i = 0; i < n - 1; i++) {
        i64 temp; cin >> temp;
        seen[temp] = true;
    }
    for(i64 i = 1; i <= n; i++) {
        if(!seen[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}