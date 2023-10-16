#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

pair<double, double> h, a, b;
double ans;

// distance between 2 coords
double euclid(pair<double, double> x, pair<double, double> y) {
    return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

void run_case() {
    cin >> h.first >> h.second >> a.first >> a.second >> b.first >> b.second;
    double oa, ob, ha, hb, ab;
    oa = euclid({0, 0}, a);
    ob = euclid({0, 0}, b);
    ha = euclid(h, a);
    hb = euclid(h, b);
    ab = euclid(a, b);
    
    if(oa < ob && ha < hb)
        ans = max(oa, ha);
    else if(ob < oa && hb < ha)
        ans = max(ob, hb);
    else
        ans = max(max(min(oa, ob), min(ha, hb)), ab / 2);
    cout << fixed << setprecision(8) << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        run_case();
    return 0;
}
