#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

const int mxN = 1e5 + 5;
int n, s[mxN];

void run_case() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    
    sort(s, s + n);
    int mex = 0;
    while(s[mex] == mex && mex < n)
        mex++;
    cout << mex << endl;
    
    int y;
    while(true) {
        cin >> y;
        if(y == -1)
            break;
        cout << y << endl;
    }
}

int main() {
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
