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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, g;
    cin >> n >> m >> g;
    vector < lli > v[g];
    vector < pair < int, int > > p[g];
    for (int i = 0, x; i < g; i++) {
        cin >> x;
        v[i].resize(x);
        p[i].resize(x);
        for (int j = 0; j < x; j++) {
            cin >> p[i][j].fi >> p[i][j].se >> v[i][j];
        }
    }
    int q;
    cin >> q;
    int which[q], cnt = 0;
    vector < pair < pair <int, int >, pair < int, int > > > P(2001);
    for (int i = 0; i < q; i++) {
        string a;
        cin >> a;
        if (a != "ASK") {
            cin >> which[i];
        } else {
            which[i] = 0;
            cin >> P[cnt].fi.fi >> P[cnt].fi.se >> P[cnt].se.fi >> P[cnt].se.se;
            cnt++;
        }
    }
    lli ans[g][cnt];
    BIT2D A(n, m);
    for (int i = 0; i < g; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            A.inc(p[i][j].fi, p[i][j].se, v[i][j]);
        }
        for (int j = 0; j < cnt; j++) {
            ans[i][j] = A.query(P[j].fi.fi, P[j].fi.se, P[j].se.fi, P[j].se.se);
        }
    }
    for (int j = 0; j < cnt; j++) {
        for (int i = g-1; i; i--) {
            ans[i][j] -= ans[i-1][j];
        }
    }
    vector< int > mark(g+1, 1);
    int cur = 0;
    for (int i = 0; i < q; i++) {
        if (which[i]) {
            mark[which[i]] = !mark[which[i]];
        } else {
            lli ret = 0;
            for (int i = 0; i < g; i++) {
                if (mark[i+1]) {
                    ret += ans[i][cur];
                }
            }
            cur++;
            cout << ret << '\n';
        }
    }
}