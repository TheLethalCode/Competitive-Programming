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
#define sz(a) (int)(a.size())
#define MAXC 505
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int n, m, ar[MAXC];
lli dp[MAXC][MAXC];

lli solve(int l, int r){
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    if(l >= r){
        return dp[l][r] = 1;
    }
    int s = MAXC, p = -1;
    for(int i=l;i<=r;i++){
        if(s > ar[i]){
            s = ar[i];
            p = i;
        }
    }
    lli ansR = (p==r)?1:(2*solve(p+1, r))%mod;
    lli ansL = (p==l)?1:(2*solve(l, p-1))%mod;
    for(int i=p+1;i<r;i++){
        ansR += solve(p+1, i)*solve(i+1, r)%mod;
        ansR %= mod;
    }
    for(int i=p-1;i>l;i--){
        ansL += solve(i, p-1)*solve(l, i-1)%mod;
        ansL %= mod;
    }
    return dp[l][r] = ansR * ansL % mod;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i, n){
        cin >> ar[i];
    }
    memset(dp, 0xff, sizeof(dp));
    cout << solve(0, n-1) << '\n';
}