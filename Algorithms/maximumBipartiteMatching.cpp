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

int M[1005], vis[1005];
vector< int > ed[1005];
int s, b;

// M[v] = u or 0 , u∈L, v∈R  #Match for v, 0 means unmatched
// |L| = s, |R| = b
// dfs(u) returns 1 if aug path exists
int dfs(int u){
    vis[u] = 1;
    FORR(v, ed[u]){
        if(!M[v] || (!vis[M[v]] && dfs(M[v]))){
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
int main(){
    
}
