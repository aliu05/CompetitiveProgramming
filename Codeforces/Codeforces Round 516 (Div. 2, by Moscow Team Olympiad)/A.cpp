#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int a[3];

void run_case() {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if(a[0] + a[1] > a[2])
        cout << 0;    
    else
        cout << a[2] - a[0] - a[1] + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    int t; cin >> t;
//    while(t--)
    run_case();
    return 0;
}
