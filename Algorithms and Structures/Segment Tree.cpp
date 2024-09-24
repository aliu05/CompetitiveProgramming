/*
    Updated: 09-23-2024
    Status:  idk
    Source:  me
    Verification: https://codeforces.com/problemset/problem/1915/F
*/

struct lzk_segtree {
    i64 N;
    vector<i64> tree;
    lzk_segtree(vector<i64> vi) {
        N = sz(vi);
        tree.resize(2 * N);
        for(i64 i = N; i < 2 * N; ++i) tree[i] = vi[i - N];
        for(i64 i = N - 1; i > 0; --i)  {
            // This determines what ranges are!
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    
    void update(i64 ind, i64 val) {
        for(i64 i = N + ind; i > 0; i /= 2) tree[i] += val;
    }

    // Inclusive range [l, r]
    i64 query(i64 l, i64 r) {
        i64 ret = 0;
        for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
            if(l % 2) ret += tree[l++];
            if(r % 2) ret += tree[--r];
        }
        return ret;
    }
};
