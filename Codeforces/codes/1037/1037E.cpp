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

int n, m, k;
pair< int, int > E[MAXC];
vector< int > ans;
set< int > to[MAXC];
set< pair< int, int > > S;

void clean(){
    while(!S.empty() && S.begin()->fi < k){
        int u = S.begin()->se;
        S.erase(S.begin());
        FORR(v, to[u]){
            S.erase({to[v].size(), v});
            to[v].erase(u);
            S.insert({to[v].size(), v});
        }
        to[u].clear();
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    FOR(i, m){
        cin >> E[i].fi >> E[i].se;
        to[E[i].fi].insert(E[i].se);
        to[E[i].se].insert(E[i].fi);
    }
    FOR(i, n){
        if(to[i+1].size()){
            S.insert({to[i+1].size(), i+1});
        }
    }
    clean();
    ans.pb(S.size());
    for(int i = m - 1; i; i--){
        int u = E[i].fi, v = E[i].se;
        if(to[u].count(v)){
            S.erase({to[v].size(), v});
            S.erase({to[u].size(), u});
            to[v].erase(u);
            to[u].erase(v);
            S.insert({to[v].size(), v});
            S.insert({to[u].size(), u});
        }
        clean();
        ans.pb(S.size());
    }
    reverse(ans.begin(), ans.end());
    FORR(x, ans){
        cout << x << '\n';
    } 
}