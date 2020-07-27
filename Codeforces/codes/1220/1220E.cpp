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
lli W[MAXC], dp[MAXC], ans = 0, dead = 0;
vector< int > ed[MAXC];
int vis[MAXC];

bool dfs(int u, int p=-1){
    vis[u] = 1;
    bool ok = false;
    FORR(v, ed[u]){
        if(v != p){
            if(vis[v]){
                ok = true;
            }
            else{
                bool temp = dfs(v, u);
                ok |= temp;
                if(!temp){
                    dp[u] = max(dp[u], dp[v]); 
                }
            }
        }
    }
    if(ok){
        ans += W[u];
    }
    else{
        dp[u] += W[u];
    }
    dead = max(dead, dp[u]);
    return ok;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s;
    cin >> n >> m;
    FOR(i, n){
        cin >> W[i+1];
    }
    FOR(i, m){
        int a, b;
        cin >> a >> b;
        ed[a].pb(b);
        ed[b].pb(a);
    }
    cin >> s;
    dfs(s);
    cout << ans + dead << "\n";
}