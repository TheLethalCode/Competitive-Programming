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

int dis[101][101], M[1005], vis[1005];
vector< int > ed[1005];
int s, b, k, h;

// M[v] = u or 0 , u∈L, v∈R  #Match for v
// |L| = s
// dfs(u) returns 1 if aug path exists. Algo runs in O(|V||E|).
int dfs(int u){
    vis[u] = 1;
    FORR(v, ed[u]){
        if(!M[v] || (!vis[M[v]]&&dfs(M[v]))){
            M[v] = u;
            return 1;
        }
    }
    return 0;
}
int match(){
    int m = 0;
    FOR(i, s){
        memset(vis, 0, sizeof(vis));
        m += dfs(i+1);
    }
    return m;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    FOR(i, n){
        dis[i+1][i+1] = 0;
    }
    FOR(i, m){
        int a, b;
        cin >> a >> b;
        dis[a][b] = dis[b][a] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cin >> s >> b >> k >> h;
    vector< pair< int, pair< int, int > > > S(s);
    vector< pair< int, int > > B(b);
    FOR(i, s){
        cin >> S[i].fi >> S[i].se.fi >> S[i].se.se; 
    }
    FOR(i, b){
        cin >> B[i].fi >> B[i].se;
    }
    FOR(i, s){
        FOR(j, b){
            if(dis[S[i].fi][B[j].fi] <= S[i].se.se && B[j].se <= S[i].se.fi){
                ed[i+1].pb(j+1);
            }
        }
    }
    cout << min(1LL*h*s, 1LL*k*match()) << '\n';
}