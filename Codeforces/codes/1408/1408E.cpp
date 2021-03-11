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
#define MAXC 100005
// %

int n, m, a[MAXC], b[MAXC], par[2*MAXC];
vector< pair< int, int > > v;

int fp(int x) {
    return par[x] == x ? x : par[x] = fp(par[x]);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + 2*MAXC, 0);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    lli tot = 0;
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        for (int j = 0, y; j < x; j++) {
            cin >> y;
            v.pb(i, y - 1);
            tot += a[i] + b[y-1];
        }
    }
    sort(v.begin(), v.end(), [&](pair< int, int > l, pair< int, int > r) {
        return a[l.fi] + b[l.se] > a[r.fi] + b[r.se];
    });

    for (auto it : v) {
        int x = fp(it.fi + n), y = fp(it.se);
        if (x == y) {
            continue;
        }
        tot -= a[it.fi] + b[it.se];
        par[x] = y;
    }
    cout << tot << '\n';
}