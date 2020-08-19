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
#define MAXC 3005
// %
int val[MAXC];
pair< int, int > L[MAXC];
vector< int > ind[MAXC];

int solve(int x) {
    if (val[x] != -1) {
        return val[x];
    }
    int n = ind[x].size();
    vector < int > bef(n), dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(ind[x].begin(), ind[x].end(), L[ind[x][i]].se + 1, [&](int j, int val) {
            return L[j].fi < val;
        }) - ind[x].begin();
        bef[i] = pos;
    }
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i+1], 1 + solve(ind[x][i]) + dp[bef[i]]); 
    }
    return val[x] = dp[0];
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ind[0].clear();
        val[0] = -1;
        FOR (i, n) {
            cin >> L[i+1].fi >> L[i+1].se;
            ind[0].pb(i+1);
            ind[i+1].clear();
            val[i+1] = -1;
        }
        sort(L + 1, L + n + 1, [](pair< int, int > x, pair< int, int > y){
            return make_pair(x.fi, y.se) < make_pair(y.fi, x.se);
        });
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n && L[j].fi <= L[i].se; j++) {
                if (L[j].se <= L[i].se) {
                    ind[i].pb(j);
                }
            }
        }
        cout << solve(0) << '\n';
    }
}