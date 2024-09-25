/*
    https://codeforces.com/gym/104713/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back
#define mp make_pair

int N, pc;
char P;
string b[105];
pair<int, int> start;
vector<pair<pair<int, int>, pair<int, int>>> ans;
set<pair<int, int>> vis;

// return neighbours
vector<pair<int, int>> getnei(char piece, pair<int, int> st) {
    vector<pair<int, int>> ret;
    if(piece == 'R') {
        for(int i = 1; i <= N; ++i) {
            if(b[i][st.second] == piece && i != st.first) {
                ret.pb(mp(i, st.second));
            }
            if(b[st.first][i] == piece && i != st.second) {
                ret.pb(mp(st.first, i));
            }
        }
    }
    if(piece == 'B') {
        int x, y;
        x = st.first - 1;
        y = st.second - 1;
        while(b[x][y] != '!') {
            if(b[x][y] == piece) {
                ret.pb(mp(x, y));
            }
            --x;
            --y;
        }

        x = st.first + 1;
        y = st.second - 1;
        while(b[x][y] != '!') {
            if(b[x][y] == piece) {
                ret.pb(mp(x, y));
            }
            ++x;
            --y;
        }
        x = st.first - 1;
        y = st.second + 1;
        while(b[x][y] != '!') {
            if(b[x][y] == piece) {
                ret.pb(mp(x, y));
            }
            --x;
            ++y;
        }
        x = st.first + 1;
        y = st.second + 1;
        while(b[x][y] != '!') {
            if(b[x][y] == piece) {
                ret.pb(mp(x, y));
            }
            ++x;
            ++y;
        }
    }
    if(piece == 'Q') {
        // rook cosplay
        for(int i = 1; i <= N; ++i) {
            if(b[i][st.second] == piece && i != st.first) {
                ret.pb(mp(i, st.second));
            }
            if(b[st.first][i] == piece && i != st.second) {
                ret.pb(mp(st.first, i));
            }
        }
        // bishop cosplay
        int x, y;
        x = st.first - 1;
        y = st.second - 1;
        while(b[x][y] != '!') {
            if(b[x][y] == piece) {
                ret.pb(mp(x, y));
            }
            --x;
            --y;
        }

        x = st.first + 1;
        y = st.second - 1;
        while(b[x][y] != '!') {
            if(b[x][y] == piece) {
                ret.pb(mp(x, y));
            }
            ++x;
            --y;
        }
        x = st.first - 1;
        y = st.second + 1;
        while(b[x][y] != '!') {
            if(b[x][y] == piece) {
                ret.pb(mp(x, y));
            }
            --x;
            ++y;
        }
        x = st.first + 1;
        y = st.second + 1;
        while(b[x][y] != '!') {
            if(b[x][y] == piece) {
                ret.pb(mp(x, y));
            }
            ++x;
            ++y;
        }
    }
    if(piece == 'K') {
        for(int i = st.first - 1; i <= st.first + 1; ++i) {
            for(int j = st.second - 1; j <= st.second + 1; ++j) {
                if(b[i][j] == piece && !(i == st.first && j == st.second)) {
                    ret.pb(mp(i, j));
                }
            }
        }
    }
    if(piece == 'N') {
        int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        for(int i = 0; i < 8; ++i) {
            if(st.first + X[i] > 0 && st.first + X[i] <= N && st.second + Y[i] > 0 && st.second + Y[i] <= N) {
                if(b[st.first + X[i]][st.second + Y[i]] == piece) {
                    ret.pb(mp(st.first + X[i], st.second + Y[i]));
                }
            }
        }
    }
    return ret;
}

void dfs(pair<int, int> node) {
    vis.insert(node);
    vector<pair<int, int>> nei = getnei(P, node);

    for(pair<int, int> e : nei) {
        if(!vis.count(e)) {
            dfs(e);
            ans.pb(mp(e, node));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> P;
    b[0] = "";
    for(int i = 0; i <= N + 1; ++i) {
        b[0] += '!';
    }
    for(int i = 1; i <= N; ++i) {
        string ttt;
        cin >> ttt;
        b[i] = ('!' + ttt + '!');
    }
    b[N + 1] = "";
    for(int i = 0; i <= N + 1; ++i) {
        b[N + 1] += '!';
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(b[i][j] == P) {
                if(pc == 0) {
                    start = mp(i, j);
                }
                pc++;
            }
        }
    }

    dfs(start);

    if(ans.size() < pc - 1) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        for(auto e : ans) {
            cout << e.first.first << ' ' <<  e.first.second << ' ' << e.second.first << ' ' << e.second.second << nl;
        }
    }
    return 0;
}
