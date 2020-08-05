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
        int n, k, ans = 0;
        cin >> n >> k;
        set< int > to[n+1];
        vector< int > leaves[n+1], S;
        FOR(i, n-1){
            int a, b;
            cin >> a >> b;
            to[a].insert(b);
            to[b].insert(a);
        }
        if(k == 1){
            cout << n - 1 << '\n';
            continue;
        }
        FOR(i, n){
            FORR(v, to[i+1]){
                if(to[v].size() == 1){
                    leaves[i+1].pb(v);
                }
            }
            if(leaves[i+1].size() >= k){
                S.pb(i+1);
            }
        }
        while(!S.empty()){
            int u = S.back();
            FOR(i, k){
                to[u].erase(leaves[u].back());
                leaves[u].pop_back();
            }
            if(leaves[u].size() < k){
                S.pop_back();
            }
            if(to[u].size() == 1){
                int v = *to[u].begin();
                leaves[v].pb(u);
                if(leaves[v].size() == k){
                    S.pb(v);
                }
            }
            ans++;
        }
        cout << ans << '\n';
    }
}