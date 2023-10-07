#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

const int mxN = 3e5;
int64_t n, a[mxN], b[mxN];

void run_case() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	
	int64_t ma, mb, sa, sb; 
	ma = LONG_MAX;
	mb = LONG_MAX;
	sa = 0;
	sb = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] < ma)
			ma = a[i];
		if(b[i] < mb)
			mb = b[i];
		sa += a[i];
		sb += b[i];
	}
	cout << min(ma * n + sb, mb * n + sa) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
