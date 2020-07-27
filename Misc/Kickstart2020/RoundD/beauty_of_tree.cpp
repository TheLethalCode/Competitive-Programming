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
#define MAXC 500005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
vector< int > ed[MAXC], Adown[MAXC], Bdown[MAXC];
vector< vector< int > > up;
int n, a, b, l, par[MAXC];
lli Acnt[MAXC], Bcnt[MAXC], beauty=0;

int goUP(int u, int dis){
    int i = 0;
    while(dis){
        if(dis&1){
            u = up[u][i];
        }
        dis /= 2;
        i++;
    }
    return u;
}

void dfs(int u, int p=0){
    up[u][0] = p;
    for(int i=1;i<=l;i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    Adown[goUP(u, a)].pb(u);
    Bdown[goUP(u, b)].pb(u);
    FORR(v, ed[u]){
        if(v != p){
            dfs(v, u);
        }
    }
    Acnt[u] = Bcnt[u] = 1;
    FORR(x, Adown[u]) {
        Acnt[u] += Acnt[x];
    }
    FORR(x, Bdown[u]){
        Bcnt[u] += Bcnt[x];
    }
    beauty += (Acnt[u]+Bcnt[u])*n - Acnt[u]*Bcnt[u];
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int z=1; z<=t; z++){
        cin >> n >> a >> b;
        l = ceil(log2(n)) + 1;
        up.resize(n+1, vector< int >(l+1));
        par[1] = beauty = 0;
        FOR(i, n+1){
            ed[i].clear();
            Adown[i].clear();
            Bdown[i].clear();
            up[i].assign(l+1, 0);
        }
        FOR(i, n-1){
            int a, b;
            cin >> b;
            a = i + 2;
            ed[a].pb(b), ed[b].pb(a);
            par[a] = b;
        }
        dfs(1);
        double ans = beauty;
        ans /= 1LL*n*n;
        cout << "Case #" << z << ": ";
        cout << fixed << setprecision(8) << ans << '\n';
    }
}