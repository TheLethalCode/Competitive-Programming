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

lli modp(lli n, lli p) {
    if (!p) {
        return 1;
    } else if (p & 1) {
        return modp(n, p - 1) * n % mod;
    } else {
        lli  t = modp(n, p >> 1);
        return t * t % mod;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    lli s;
    cin >> n >> s;
    vector < lli > V(n);
    FOR (i, n) {
        cin >> V[i];
    }
    vector < lli > fact(n+1, 1), Ifact(n+1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i-1] * i % mod;
        Ifact[i] = modp(fact[i], mod - 2);
    }
    auto poss = [&](lli r) -> lli {
        if (r < 0) {
            return 0;
        }
        lli ans = 1;
        for (int i = 0; i < n-1; i++) {
            ans = ans * ((r + n - i - 1) % mod) % mod;
        }
        ans = ans * Ifact[n-1] % mod;
        return ans;
    };
    lli ans = 0;
    for (int i = 0; i < (1<<n); i++) {
        int ch = 1;
        lli cur = s;
        for (int j = 0; j < n; j++) {
            if (i & 1<<j) {
                cur -= V[j] + 1;
                ch = -ch;
            }
        }
        ans = (ans + ch * poss(cur)) % mod;
        ans = (ans + mod) % mod;
    }
    cout << ans << '\n';
}