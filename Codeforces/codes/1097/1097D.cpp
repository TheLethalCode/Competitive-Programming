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
#define MAXC 10005
// %
lli n, k, ans = 1, Imod[61];
lli modpow(lli n, lli p){
    if(!p){
        return 1;
    }
    if(p&1){
        return modpow(n, p-1) * n % mod;
    }
    lli t = modpow(n, p>>1);
    return t * t % mod;
}

inline lli modI(lli n){
    return modpow(n, mod-2);
}

lli solve(lli p, int i){
    lli dp[k+1][i+1], ans = 0, var = 1;
    memset(dp, 0, sizeof(dp));
    dp[0][i] = 1;
    for(int x=1;x<=k;x++){
        dp[x][i] = dp[x-1][i] * Imod[i+1] % mod;
        for(int y=i-1;y>=0;y--){
            dp[x][y] = dp[x][y+1] + dp[x-1][y] * Imod[y+1];
            dp[x][y] %= mod;
        }
    }
    FOR(y, i+1){
        ans = (ans + dp[k][y] * var) % mod;
        var = var * p % mod;
    }
    return ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    vector< pair< lli, int > > v;
    for(int i=2;1LL*i*i <= n;i++){
        int cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt++;
        }
        if(cnt){
            v.pb(i, cnt);
        }
    }
    if(n != 1){
        v.pb(n, 1);
    }
    FOR(i, 60){
        Imod[i+1] = modI(i+1);
    }
    FORR(el, v){
        ans = ans * solve(el.fi, el.se) % mod;
    }
    cout << ans << '\n';
}