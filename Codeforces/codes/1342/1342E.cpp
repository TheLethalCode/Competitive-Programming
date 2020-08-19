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

lli modp(lli n, lli p){
    if (!p) {
        return 1;
    } else if (p & 1) {
        return modp(n, p-1) * n % mod;
    } else {
        lli t = modp(n, p>>1);
        return t * t % mod;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector< lli > fact(MAXC, 1), Ifact(MAXC, 1);
    for (int i = 2; i < MAXC; i++) {
        fact[i] = fact[i-1] * i % mod;
        Ifact[i] = modp(fact[i], mod - 2);
    }
    auto ncr = [&](int n, int r)->lli{
        if (r > n) {
            return 0;
        }
        lli ans = Ifact[n-r] * Ifact[r] % mod;
        return ans * fact[n] % mod;
    };
    if (k == 0) {
        cout << fact[n] << '\n';
        return 0;
    }
    lli ans = 0;
    int ch = 1;
    for (int i = 0; i < n - k; i++) {
        ans = (ans + ch * ncr(n - k, i) * modp(n - k - i, n) + mod) % mod;
        ch = -ch;
    }
    cout << 2 * ncr(n, k) * ans % mod << '\n';
    return 0;
}