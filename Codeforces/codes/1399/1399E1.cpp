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
vector< pair< int, int > > to[MAXC];
int times[MAXC];

int dfs(int u, int p = 0){
    int mark = 0;
    FORR(v, to[u]){
        if(v.fi != p){
            int temp = dfs(v.fi, u);
            times[v.se] = temp;
            mark += temp;
        }
    }
    return mark?mark:1;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        lli S, cur = 0, ans = 0;
        cin >> n >> S;
        vector< int > E(n-1);
        FOR(i, n){
            to[i+1].clear();
            times[i] = 0;
        }
        FOR(i, n-1){
            int a, b;
            cin >> a >> b >> E[i];
            to[a].pb(b, i);
            to[b].pb(a, i);
        }
        dfs(1);
        set< pair< lli, int >, greater< pair< lli, int > > > con;
        FOR(i, n-1){
            cur += 1LL * times[i] * E[i];
            con.insert({1LL * times[i] * (E[i] - E[i] / 2), i});
        }
        while(cur > S){
            int i = con.begin()->se;
            cur -= con.begin()->fi;
            E[i] >>= 1;
            con.erase(con.begin());
            con.insert({1LL * times[i] * (E[i] - E[i] / 2), i});
            ans++;
        }
        cout << ans << '\n';
    }   
}