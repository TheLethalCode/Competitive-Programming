#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 998244353
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %
lli n, k, x, dp[MAXC][2];
vector< int > a1, a2;

lli solve(vector< int > &v){
    lli ans = 1;
    int n = v.size();
    vector< int > edge;
    FOR(i, n){
        if(~v[i]){
            edge.pb(i);
        }
    }
    for(int i=1;i<edge.size();i++){
        ans = ans * dp[edge[i]-edge[i-1]-1][(v[edge[i]]==v[edge[i-1]]?0:1)] % mod;
    }
    if(edge.empty()){
        ans = v.size()==1?k:k*dp[n-2][0]%mod + k*(k-1)%mod * dp[n-2][1]%mod;
        ans %= mod;
    }
    else{
        if(edge[0] != 0){
            ans *= (dp[edge[0]-1][0] + (k-1)*dp[edge[0]-1][1])%mod;
            ans %= mod;
        }
        if(edge.back() != n-1){
            ans *= (dp[n-edge.back()-2][0] + (k-1)*dp[n-edge.back()-2][1])%mod;
            ans %= mod;
        }
    }
    return ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    dp[0][1] = 1;
    FOR(i, n){
        cin >> x;
        (i&1)?a1.pb(x):a2.pb(x);
        dp[i+1][0] = (k-1)*dp[i][1]%mod;
        dp[i+1][1] = (dp[i][0] + (k-2)*dp[i][1])%mod;
    }
    cout << solve(a1) * solve(a2) % mod << '\n';
}