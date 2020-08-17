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
#define MAXC 3005
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, c, k;
        cin >> n >> c >> k;
        map< int, int > mp[c];
        vector< int > cost(c), sl[c];
        vector< pair< lli, int > > memo(c);
        lli orig = 0;
        FOR(i, n){
            int a, b, d;
            cin >> a >> b >> d;
            mp[d-1][a]++;
        }
        FOR(i, c){
            FORR(el, mp[i]){
                sl[i].pb(el.se);
                memo[i].fi += el.se * (el.se - 1) / 2;
                memo[i].se += el.se;
            }
            sort(sl[i].rbegin(), sl[i].rend());
            cin >> cost[i];
        }
        vector< pair< int , lli > > V;
        FOR(i, c){
            while(!sl[i].empty()){
                int x = sl[i].back();
                lli diff = (memo[i].se-x)*(memo[i].se-x-1)/2 - memo[i].fi + x*(x-1)/2;
                V.pb(diff, cost[i]);
                memo[i].se--;
                memo[i].fi -= x*(x-1)/2 - (x-1)*(x-2)/2;
                sl[i].back()--;
                if(!sl[i].back()){
                    sl[i].pop_back();
                }
                orig += diff;
            }
        }
        lli dp[n+1][MAXC];
        memset(dp, 0, sizeof(dp));
        FOR(i, n){
            FOR(j, MAXC){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                if(V[i].se <= j){
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j-V[i].se] + V[i].fi);
                }
            }
        }
        cout << orig - *max_element(dp[n], dp[n] + k + 1) << '\n';
    }
}