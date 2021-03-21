#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 998244353
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 5005
// %

lli dp[MAXC][MAXC], ans = 0;
vector< int > to[MAXC];
int n, k;

int dfs(int u, int p = 0) {
    dp[u][0] = 1;
    int maxH = 0; // MaxLength seen till now;
    for (int v : to[u]) {
        if (v != p) {
            int curH = dfs(v, u), size = min(k, max(curH + 1, maxH)); // Max path legnth in the subtree rooted at v;
            vector< lli > temp(size + 1, 0); 
            for (int i = 0; i <= min(maxH, k); i++) { // Iterate all possible maxLength till now
                for (int j = 0; j <= min(curH, k); j++) { // Iterate all possible maxLength of subtree at v
                    if (i + j + 1 <= k) { // See if sum of length of the path of both trees is <= k
                        int in = max(i, j + 1);
                        temp[in] += dp[u][i] * dp[v][j] % mod;
                        if (temp[in] >= mod) {
                            temp[in] -= mod;
                        }
                    }
                    temp[i] += dp[u][i] * dp[v][j] % mod; // Do not include the edge
                    if (temp[i] >= mod) {
                        temp[i] -= mod;
                    } 
                }
            }
            for (int i = 0; i <= size; i++) {
                dp[u][i] = temp[i];
            }
            maxH = max(maxH, curH + 1);
        }
    }
    if (u == 1) {
        for (int i = 0; i <= k; i++) {
            ans += dp[1][i];
            if (ans >= mod) {
                ans -= mod;
            }
        }
    }
    return maxH;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0, x, y; i < n - 1; i++) {
        cin >> x >> y;
        to[x].pb(y);
        to[y].pb(x);
    }
    dfs(1);
    cout << ans << "\n";
}