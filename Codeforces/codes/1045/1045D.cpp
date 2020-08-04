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
#define MAXC 100005
// %

int a, b, n, q, P[MAXC];
double ans, C[MAXC], S[MAXC];
vector< int > to[MAXC];

void dfs(int u, int p = -1){
    P[u] = p;
    FORR(v, to[u]){
        if(v != p){
            C[u] += 1 - S[v];
            dfs(v, u);
        }
    }
    ans += C[u] * S[u];
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, n){
        cin >> S[i];
    }
    S[n] = 1;
    FOR(i, n-1){
        cin >> a >> b;
        to[a].pb(b);
        to[b].pb(a);
    }
    to[n].pb(0);
    dfs(n);
    cin >> q;
    cout << fixed << setprecision(6);
    while(q--){
        int u;
        double p;
        cin >> u >> p;
        ans += (p - S[u]) * (C[u] - S[P[u]]);
        C[P[u]] += S[u] - p;
        S[u] = p;
        cout << ans << '\n';
    }
}