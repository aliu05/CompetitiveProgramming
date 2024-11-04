#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    i64 n = (i64)s.size();
    i64 ans = 1, len = 1;
    for(i64 i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) len = 1;
        else len++;
        ans = min(ans, len);
    }
    cout << ans;
    return 0;
}