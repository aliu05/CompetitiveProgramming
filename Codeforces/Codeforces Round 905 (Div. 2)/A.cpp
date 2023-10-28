#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back
#define mp make_pair

int n, k, cc[150];
string s;

// even number of all letters and allow one odd number -> palindrome
// turn any odd occ even in 1 move
void run_case() {
    cin >> n >> k >> s;
    for(int i = 0; i < 150; ++i)
        cc[i] = 0;
    for(int i = 0; i < n; ++i)
        cc[s[i]]++;
    int e, o;
    e = o = 0;
    for(int i = (int) 'a'; i <= (int) 'z'; ++i) {
        if(cc[i] & 1)
            o++;
        else
            e++;
    }
    cout << (o - k <= 1 ? "YES" : "NO") << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
