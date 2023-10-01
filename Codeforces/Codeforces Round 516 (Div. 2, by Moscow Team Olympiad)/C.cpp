#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int n;
string s;

void run_case() {
    cin >> n >> s;
    sort(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    int t; cin >> t;
//    while(t--)
    run_case();
    return 0;
}
