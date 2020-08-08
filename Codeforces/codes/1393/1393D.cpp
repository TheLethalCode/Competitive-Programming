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
    int n, m;
    cin >> n >> m;
    int V[n+m+2][n+m+2], dp[n+m+2][n+m+2];
    lli ans = 0;
    char t;
    memset(V, 0xff, sizeof(V));
    memset(dp, 0, sizeof(dp));
    FOR(i, n){
        FOR(j, m){
            cin >> t;
            V[i+j+2][i-j+m+1] = t - 'a';
        }
    }
    for(int i=2;i<=n+m+1;i++){
        for(int j=2;j<=n+m+1;j++){
            if(V[i][j] == -1){
                dp[i][j] = 0;
            }
            else if(V[i][j] == V[i-2][j] && V[i][j] == V[i][j-2] && V[i][j] == V[i-2][j-2] && V[i][j] == V[i-1][j-1]){
                dp[i][j] = min(dp[i][j-2], min(dp[i-2][j], dp[i-2][j-2])) + 1;
            }
            else{
                dp[i][j] = 1;
            }
            ans += dp[i][j];
        }
    }
    cout << ans << '\n';
}
