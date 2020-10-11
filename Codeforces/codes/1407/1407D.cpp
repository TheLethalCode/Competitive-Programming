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
    int n;
    cin >> n;
    vector< int > v(n), ne[2], pr[2];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int _ = 0; _ < 2; _++) {
        for (auto &x : v) {
            x = -x;
        }
        vector< pair< int, int > > nB = {{mod, n}};
        for (int i = n - 1; i >= 0; i--) {
            while (!nB.empty() && nB.back().fi < v[i]) {
                nB.pop_back();
            }
            ne[_].pb(nB.back().se);
            nB.push_back({v[i], i});
        }
        reverse(ne[_].begin(), ne[_].end());
        nB = {{mod, n}};
        for (int i = 0; i < n; i++) {
            while (!nB.empty() && nB.back().fi < v[i]) {
                nB.pop_back();
            }
            pr[_].pb(nB.back().se);
            nB.push_back({v[i], i});
        }
    }
    vector< int > to[n+1];
    for (int _ = 0; _ < 2; _++) {
        for (int i  = 0; i < n; i++) {
            to[i].pb(ne[_][i]);
            to[pr[_][i]].pb(i);
        }
    }
    int dp[n+1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int v : to[i]) {
            dp[v] = min(dp[v], dp[i] + 1);
        }
    }
    cout << dp[n-1] << '\n';
}