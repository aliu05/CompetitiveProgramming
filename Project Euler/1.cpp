#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    for(int i = 3; i < 1000; ++i) {
        if(!(i % 3 && i % 5))
            ans += i;
    }
    cout << ans;
    return 0;
}
