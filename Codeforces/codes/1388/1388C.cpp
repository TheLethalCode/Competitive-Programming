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
int n, m, P[MAXC], H[MAXC], S[MAXC], ok;
vector< int > to[MAXC];

pair< lli, lli > dfs(int u, int p=0){
    S[u] = P[u];
    lli ch = 0, cs = 0;
    FORR(v, to[u]){
        if(v!=p){
            pair<lli, lli > te = dfs(v, u);
            ch += te.fi, cs += te.se;
            S[u] += S[v];
        }
    }
    if((H[u] + S[u])%2==0){
        lli h = H[u] + S[u] >> 1, s = S[u] - H[u] >> 1;
        if(ch > h || h < 0 || s < 0){
            ok = 0;
        }
        return {h, s};
    }
    ok = 0;
    return {0, 0};
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ok = 1;
        FOR(i, n){
            to[i+1].clear();
        }
        FOR(i, n){
            cin >> P[i+1];
        }
        FOR(i, n){
            cin >> H[i+1];
        }
        FOR(i, n-1){
            int a, b;
            cin >> a >> b;
            to[a].pb(b);
            to[b].pb(a);
        }
        dfs(1);
        cout << (ok?"YES":"NO") << '\n';
    }
}