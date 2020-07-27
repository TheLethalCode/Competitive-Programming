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

int vis[MAXC], tout[MAXC], n, m, ti = 0, ok = 1;
vector< int > ed[MAXC];
vector< pair< int, int > > E;

void dfs(int u){
    ti++;
    vis[u] = 2;
    FORR(v, ed[u]){
        ok &= vis[v]!=2;
        if(!vis[v]){
            dfs(v);
        }
    }
    tout[u] = ti++;
    vis[u] = 1;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        E.clear();
        FOR(i, n){
            ed[i+1].clear();
            vis[i+1] = 0;
        }
        FOR(i, m){
            int t, a, b;
            cin >> t >> a >> b;
            t?ed[a].pb(b):E.pb(a, b);
        }
        FOR(i, n){
            if(!vis[i+1]){
                dfs(i+1);
            }
        }
        FORR(e, E){
            if(tout[e.fi] > tout[e.se]){
                ed[e.fi].pb(e.se);
            }
            else{
                ed[e.se].pb(e.fi);
            }
        }
        if(ok){
            cout << "YES\n";
            FOR(i, n){
                FORR(v, ed[i+1]){
                    cout << i+1 << " " << v << '\n';
                }
            }
        }
        else{
            cout << "NO\n";
            ok = 1;
        }
        ti = 0;
    }
}