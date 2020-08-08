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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        set< int > to[n+1];
        FOR(i, m){
            int a, b;
            cin >> a >> b;
            to[a].insert(b);
            to[b].insert(a);
        }
        set< pair< int, int > > S;
        FOR(i, n){
            S.insert({to[i+1].size(), i+1});
        }
        while(!S.empty() && S.begin()->fi < k){
            int u = S.begin()->se;
            FORR(v, to[u]){
                if(to[v].count(u)){
                    S.erase({to[v].size(), v});
                    to[v].erase(u);
                    S.insert({to[v].size(), v});
                }
            }
            to[u].clear();
            S.erase(S.begin());
        }
        cout << S.size() << '\n';
    }
}