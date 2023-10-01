#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

const int mxN = 100;
int n, s[mxN], e[mxN];

void run_case() {
    cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> s[i] >> e[i];
	
	for(int i = 1; i < n; ++i) {
		if(s[i] >= s[0] && e[i] >= e[0]) {
			cout << -1 << nl;
			return;
		}
	}
	cout << s[0] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
