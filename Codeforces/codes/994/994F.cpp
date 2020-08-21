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
#define MAXC 55
#define RAN 5005
// %

int n;
vector< pair< lli, lli > > V(MAXC);
lli dp[2][MAXC][MAXC][RAN];

inline void chmin(lli &x, lli y){
    x = min(x, y);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR (i, n) {
        cin >> V[i].fi;
    }
    FOR (i, n) {
        cin >> V[i].se;
    }
    sort(V.rbegin(), V.rend());
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < MAXC; j++) {
            for (int k = 0; k < MAXC; k++) {
                for (int l = 0; l < RAN; l++) {
                    dp[i][j][k][l] = 10000LL * mod;
                }
            }
        }
    }
    dp[1][0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; j + k <= i; k++) {
                for (int l = 0; l <= 100*i; l++) {
                    dp[1 - (i&1)][j][k][l] = 10000LL * mod;
                    if (i > 1 && V[i-1].fi != V[i-2].fi) {
                        chmin(dp[i&1][j+k][0][l], dp[i&1][j][k][l]);
                    }
                }
            }
        }
        for (int j = 0; j <= i; j++) {
            for (int k = 0; j + k <= i; k++){
                for (int l = 0; l <= 100*i; l++) {
                    if (k && l >= V[i-1].se) {
                        chmin(dp[1 - (i&1)][j][k][l], dp[i&1][j][k-1][l - V[i-1].se] + V[i-1].fi);
                    }
                    chmin(dp[1 - (i&1)][j][k][l], dp[i&1][j+1][k][l]);
                }
            }
        }
    }
    lli ans = 1LL * mod * mod;
    for (int j = 0; j <= n; j++) {
        for (int k = 0; j + k <= n; k++) {
            for (int l = 1; l <= n*100; l++) {
                ans = min(ans, (1000 * dp[1-(n&1)][j][k][l] + l - 1) / l);
            }
        }
    }
    cout << ans << '\n';
}