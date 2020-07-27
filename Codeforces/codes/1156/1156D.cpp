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
#define sz(a) (int)(a.size())
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int n, a, b, c;
vector< int > ed[MAXC][2];
lli dp[MAXC][4], ans = 0;

void dfs(int u, int p=-1){
    FORR(v, ed[u][0]){
        if(v != p){
            dfs(v, u);
            dp[u][0] += 1 + dp[v][0];
            dp[u][1] += dp[v][1] + dp[v][2];
        }
    }
    FORR(v, ed[u][1]){
        if(v != p){
            dfs(v, u);
            dp[u][2] += 1 + dp[v][2];
            dp[u][3] += dp[v][0] + dp[v][3];
        }
    }
    ans += 2*(dp[u][0] + dp[u][2]) + dp[u][1] + dp[u][3];
    FORR(v, ed[u][0]){
        if(v != p){
            ans += (dp[u][0] - 1 - dp[v][0]) * (1 + dp[v][0] + dp[v][1] + dp[v][2]);
        }
    }
    FORR(v, ed[u][1]){
        if(v != p){
            ans += (dp[u][0] + dp[u][3] - dp[v][3] - dp[v][0]) * (1 + dp[v][2]);
            ans += (dp[u][2] - 1 - dp[v][2]) * (1 + dp[v][2]);
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, n-1){
        cin >> a >> b >> c;
        ed[a][c].pb(b);
        ed[b][c].pb(a);
    }
    dfs(1);
    cout << ans << '\n';
}