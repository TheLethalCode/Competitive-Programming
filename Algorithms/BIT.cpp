#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %
// Zero Indexed Binary Indexed Tree.
struct BIT {
    int n;
    vector < lli > bit;
    BIT (int _n) : n(_n) {
        bit.assign(n, 0);
    }
    BIT (vector< lli > &v) : BIT(v.size()) {
        for (int i = 0; i < n; i++) {
            inc(i, v[i]);
        }
    }
    lli sum(int r) {
        lli ret = 0;
        for (;r >= 0; r = (r & (r+1)) - 1) {
            ret += bit[r];
        }
        return ret;
    }
    void inc(int i, lli del) {
        for (;i < n; i = i | (i+1)) {
            bit[i] += del;
        }
    }

    void reset(int _n) {
        n = _n;
        bit.assign(n, 0);
    }
    lli sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

struct BIT2D {
    vector < vector < lli > > V;
    int n, m;
    BIT2D (int _n, int _m) : n(_n+1), m(_m+1) {
        V.resize(n, vector<lli>(m, 0));
    }
    lli sum(int i, int j) {
        lli ret = 0;
        for (int x = i; x >= 0; x = (x & (x+1)) - 1) {
            for (int y = j; y >= 0; y = (y & (y+1)) - 1) {
                ret += V[x][y];
            }
        }
        return ret;
    }
    void inc(int i, int j, lli val) {
        for (int x = i; x < n; x = x | (x + 1)) {
            for (int y = j; y < m; y = y | (y + 1)) {
                V[x][y] += val;
            }
        }
    }

    lli query(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1 - 1);
    }
};