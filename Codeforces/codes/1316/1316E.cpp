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
    int n, p, k;
    cin >> n >> p >> k;
    vector < vector< lli > > V(n, vector<lli>(p+1));
    FOR (i, n) {
        cin >> V[i][0];
    }    
    FOR (i, n) {
        FOR (j, p) {
            cin >> V[i][j+1];
        }
    }
    sort(V.rbegin(), V.rend());
    lli dp[n+1][1<<p];
    memset(dp, 0xff, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1<<p); j++) {
            if (dp[i][j] != -1) {
                if (__builtin_popcount(j) + k > i) {
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + V[i][0]);
                } else {
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                }
                for (int k = 0; k < p; k++) {
                    if (!(j & 1<<k)) {
                        dp[i+1][j|1<<k] = max(dp[i+1][j|1<<k], dp[i][j] + V[i][k+1]);
                    }
                }
            }
        }
    }
    cout << dp[n][(1<<p)-1] << '\n';
}