#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

const int MOD = 998244353;
string s;
int64_t ans, dif;

int64_t fac(int64_t n) {
	int64_t ret = 1;
	for(int64_t i = 2; i <= n; ++i)
		ret = (ret * i) % MOD;
	return ret;
}

void run_case() {
	cin >> s;
	ans = 0;
	dif = 1;
	// ans * len of each consec section
	// 1100 -> 8
	int64_t consec = 1;
	for(int i = 1; i < s.length(); ++i) {
		if(s[i] != s[i - 1]) {
			dif = (dif * consec) % MOD;
			ans += consec - 1;
			consec = 0;
		}
		++consec;
	}
	ans += consec - 1;
	dif = (dif * consec) % MOD;
	dif = (dif * fac(ans)) % MOD;
	cout << ans << ' ' << dif << nl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		run_case();
	return 0;
}
