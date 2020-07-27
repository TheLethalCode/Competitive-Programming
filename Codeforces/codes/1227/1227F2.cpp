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
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

lli pomo(lli n, lli p){
    if(!p){
        return 1;
    }
    else if(p&1){
        return pomo(n, p-1) * n % mod;
    }
    lli t = pomo(n, p>>1);
    return t * t % mod;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector< int > v(n);
    vector< lli > f(n+1, 1), finv(n+1, 1), k2pow(n+1, 1);
    for(int i=1;i<=n;i++){
        f[i] = f[i-1] * i % mod;
        finv[i] = pomo(f[i], mod-2);
        k2pow[i] = k2pow[i-1] * (k-2) % mod;
    }
    FOR(i, n){
        cin >> v[i];
    }
    lli x = 0, y = 0, ans = 0;
    FOR(i, n){
        (v[(i+1)%n] == v[i]? y : x)++; 
    }
    for(int i=0;2*i<=x;i++){
        lli temp = f[x] * finv[i] % mod;
        temp = temp * finv[i] % mod;
        temp = temp * finv[x-2*i] % mod;
        temp = temp * k2pow[x-2*i] % mod;
        ans = (ans + temp) % mod; 
    }
    ans = (pomo(k, x) - ans + mod) % mod;
    ans = ans * pomo(2, mod-2) % mod;
    ans = ans * pomo(k, y) % mod;
    cout << ans << "\n";
}