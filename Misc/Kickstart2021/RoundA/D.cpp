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
#define MAXC 1005
// %

int par[MAXC];
int fp(int x) {
    return x == par[x]? x: par[x] = fp(par[x]);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n;
        cin >> n;
        vector< vector< int > > A(n, vector<int>(n)), B(n, vector<int>(n));
        vector< pair< int, pair< int, int > > > pos;
        lli ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> A[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> B[i][j];
                if (A[i][j] == -1) {
                    pos.pb(B[i][j], make_pair(i, j));
                }
                ans += B[i][j];
            }
        }
        for (int i = 0; i < 2*n; i++) {
            cin >> par[i];
        }
        iota(par, par + 2*n, 0);
        sort(pos.rbegin(), pos.rend());
        for (auto E: pos) {
            int x = fp(E.se.fi), y = fp(E.se.se + n);
            if (x != y) {
                ans -= E.fi;
                par[x] = y;
            }
        }
        cout << "Case #"<< z << ": " << ans << "\n";
    }
}