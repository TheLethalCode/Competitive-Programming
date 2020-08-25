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
#define MAXC 100005
// %

lli modp(lli n, lli p) {
    if (!p) {
        return 1;
    } else if (p & 1) {
        return modp(n, p - 1) * n % mod;
    } else {
        lli t = modp(n, p >> 1);
        return t * t  % mod;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // mobius function
    vector < int > mobius(MAXC), prime;
    vector< bool > is_prime(MAXC, 1);
    is_prime[1] = is_prime[0] = 0;
    mobius[1] = 1;
    for (int i = 2; i < MAXC; i++) {
        if (is_prime[i]) {
            prime.pb(i);
            mobius[i] = -1;
        }
        for (auto p : prime) {
            if (p * i >= MAXC) {
                break;
            }
            is_prime[p * i] = false;
            if (i % p == 0) {
                break;
            }
            mobius[p * i] = mobius[p] * mobius[i];
        }
    }

    // factorial & ncr
    vector < lli > fact(MAXC, 1), Ifact(MAXC, 1);
    for (int i = 2; i < MAXC; i++) {
        fact[i] = fact[i-1] * i % mod;
        Ifact[i] = modp(fact[i], mod-2);
    }
    auto ncr = [&](int n, int r) -> lli {
        if (n < r || r < 0) {
            return 0;
        }
        lli ans = Ifact[r] * Ifact[n-r] % mod;
        return ans * fact[n] % mod;
    };

    // factors
    vector < int > factors[MAXC];
    for (int i = 1; i < MAXC; i++) {
        for (int j = i; j < MAXC; j+=i) {
            factors[j].pb(i);
        } 
    }

    // P(n, f) = n - 1 C f - 1;
    auto P = [&](int n, int f) -> lli {
        return ncr(n-1, f-1);
    };

    int q;
    cin >> q;
    while (q--) {
        int n, f;
        cin >> n >> f;
        lli ans = 0;
        FORR (v, factors[n]) {
            ans += mobius[v] * P(n/v, f) + mod;
            ans %= mod;
        }
        cout << ans << '\n';
    }
}