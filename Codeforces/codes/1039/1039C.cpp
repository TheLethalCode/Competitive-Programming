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
#define MAXC 500005
// %

vector< int > mark(MAXC, 0), vis(MAXC, 0), to[MAXC];

lli modpow(lli n, lli p){
    if(!p){
        return 1;
    }
    if(p&1){
        return modpow(n, p-1) * n  % mod;
    }
    lli t = modpow(n, p>>1);
    return t * t  % mod;
}

int dfs(int u){
    vis[u] = 1;
    int cnt = 1;
    FORR(v, to[u]){
        if(!vis[v]){
            cnt += dfs(v);
        }
    }
    return cnt;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector< lli > v(n+1);
    FOR(i, n){
        cin >> v[i+1];
    }
    map< lli, vector< pair< int, int > > > cnt;
    FOR(i, m){
        int a, b;
        cin >> a >> b;
        cnt[v[a] xor v[b]].pb(a, b); 
    }
    lli ans = modpow(2, n) * (modpow(2, k) - (int)cnt.size() + mod) % mod;
    FORR(x, cnt){
        int sub = 0;
        vector< int > vert;
        FORR(ed, x.se){
            if(!mark[ed.fi]){
                vert.pb(ed.fi);
                mark[ed.fi]=1;
            }
            if(!mark[ed.se]){
                vert.pb(ed.se);
                mark[ed.se]=1;
            }
            to[ed.fi].pb(ed.se);
            to[ed.se].pb(ed.fi);
        }
        FORR(v, vert){
            if(!vis[v]){
                sub += dfs(v) - 1;
            }
            to[v].clear();
            mark[v] = 0;
            vis[v] = 0;
        }
        ans += modpow(2, n-sub);
        if(ans >= mod){
            ans -= mod;
        }
    }
    cout << ans << '\n';
}