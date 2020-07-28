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
#define MAXC 5005
// %

int n, m, a, b, s, t, q, ok, cnt, V[MAXC], vis[MAXC], visSCC[MAXC];
lli k, r, x, y, z, ans;
vector< int > to[MAXC];

void dfs(int u){
    t++;
    V[u] = 1;
    FORR(v, to[u]){
        if(!V[v]){
            dfs(v);
        }
    }
    V[u] = t++;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    FOR(i, m){
        cin >> a >> b;
        to[a].pb(b);
    }
    FOR(i, n){
        if(!V[i+1]){
            dfs(i+1);
        }
    }
    vector< int > ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int i ,int j){
        return V[i] > V[j];
    });
    memset(V, 0, sizeof(V));
    dfs(s);
    FORR(i, ord){
        if(!V[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << '\n';
}