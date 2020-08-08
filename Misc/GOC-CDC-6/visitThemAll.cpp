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

lli edge[19][19], dp[19][1<<19];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    FOR(i, n+1){
        FOR(j, n+1){
            edge[i][j] = mod * (i != j);
        }
    }
    FOR(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a-1][b-1] = edge[b-1][a-1] = c;
    }
    FOR(k, n){
        FOR(i, n){
            FOR(j, n){
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }
    FOR(i, n){
        FOR(j, 1<<n){
            dp[i][j] = mod;
        }
    }
    dp[0][1] = 0;
    FOR(i, 1<<n){
        FOR(j, n){
            if(i & 1<<j){
                FOR(k, n){
                    if(!(i & 1<<k)){
                        dp[k][i | 1 << k] = min(dp[k][i | 1 << k], dp[j][i] + edge[j][k]);
                    }
                }
            }
        }
    }
    cout << dp[n-1][(1<<n)-1] << '\n';
}