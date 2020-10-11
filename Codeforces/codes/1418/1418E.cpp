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

lli modp(lli n, lli p) {
    if (!p) {
        return 1;
    } else if (p & 1) {
        return modp(n, p - 1) * n % mod;
    } else {
        lli t = modp(n, p >> 1);
        return t * t % mod;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector< lli > V(n), pref(n+2, 0), fact(n+1, 1), Ifact(n+1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i  % mod;
        Ifact[i] = modp(fact[i], mod - 2);
    }
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    sort(V.begin(), V.end());
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + V[i-1];
        pref[i] %= mod;
    }
    while (m--) {
        lli a, b;
        cin >> a >> b;
        int H = V.end() - lower_bound(V.begin(), V.end(), b);
        if (H < a) {
            cout << "0\n";
            continue;
        }
        lli t1, t2;
        t1 = fact[n] * fact[H] % mod, t1 = Ifact[H+1] * t1 % mod, t1 = t1 * (H - a + 1) % mod;
        t2 = fact[n] * fact[H-1] % mod, t2 = Ifact[H] * t2 % mod, t2 = t2 * (H - a) % mod;
        lli ans = (pref[n - H] * t1 + (pref[n] - pref[n - H] + mod) * t2) % mod;
        cout << ans * Ifact[n] % mod << '\n';
    }
}