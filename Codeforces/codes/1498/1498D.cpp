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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int from[m + 5][n + 5];
    for (int i = 0; i < m + 5; i++) {
        for (int j = 0; j < n + 5; j++) {
            from[i][j] = MAXC;
        }
    }
    from[0][0] = 0;

    vector< pair< int, pair< lli, int > > > Q(n);
    for (int i = 0; i < n; i++) {
        cin >> Q[i].fi >> Q[i].se.fi >> Q[i].se.se;
    }

    for (int i = 0; i <= m; i++) {
        bool ok = false;
        for (int j = 0; j < n; j++) {
            if (from[i][j] != MAXC){
                if (!ok && i >= 1) {
                    cout << j + 1 << " ";
                    ok = true;
                }
                from[i][j + 1] = 0;
                if (from[i][j] < Q[j].se.se) {
                    lli k;
                    if (Q[j].fi == 1) {
                        k = ceil(i + 1.0 * Q[j].se.fi / 100000);
                    } else {
                        k = ceil(1.0 * i * Q[j].se.fi / 100000);
                    }
                    if (k <= m) {
                        from[k][j] = min(from[k][j], from[i][j] + 1);
                    }
                    
                }
            }
        }
        if (!ok && i >= 1) {
            cout << "-1 ";
        }
    }
    cout << "\n";
}