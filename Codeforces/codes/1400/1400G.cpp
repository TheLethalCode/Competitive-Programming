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
#define MAXC 300005
// %

lli modp(lli n, lli p) {
    if (!p) {
        return 1;
    } else if (p & 1) {
        return modp(n, p-1) * n % mod;
    } else {
        lli t = modp(n, p>>1);
        return t * t % mod;
    }
}

int cnt[MAXC];
lli ncP[MAXC][42];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector < pair < int, int > > V(n);
    FOR (i, n) {
        cin >> V[i].fi >> V[i].se;
        cnt[V[i].fi]++;
        cnt[V[i].se+1]--;
    }
    for (int i = 1; i < MAXC; i++) {
        cnt[i] += cnt[i-1];
    }
    
    vector < lli > fact(MAXC, 1), Ifact(MAXC, 1);
    for (int i = 2; i < MAXC; i++) {
        fact[i] = fact[i-1] * i % mod;
        Ifact[i] = modp(fact[i], mod - 2);
    }
    auto ncr = [&] (int n, int r) -> lli {
        if (n < r || r < 0) {
            return 0;
        }
        lli ans = Ifact[n-r] * Ifact[r] % mod;
        return ans * fact[n] % mod;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2*m; j++) {
            ncP[i][j] = (ncP[i-1][j] + ncr(cnt[i] - j, i - j)) % mod;
        }
    }

    vector < pair < int, int > > H(m);
    FOR (i, m) {
        cin >> H[i].fi >> H[i].se;
        H[i].fi--, H[i].se--;
    }

    lli ans = 0;
    for (int i = 0; i < (1<<m); i++) {
        int ch = 1, l = 1, r = n;
        set < int > S;
        for (int j = 0; j < m; j++) {
            if (i & 1<<j) {
                ch = -ch;
                l = max(l, V[H[j].fi].fi), r = min(r, V[H[j].fi].se);
                l = max(l, V[H[j].se].fi), r = min(r, V[H[j].se].se);
                S.insert(H[j].fi);
                S.insert(H[j].se);
            }
        }
        int rem = S.size();
        if (r >= l) {
            ans = (ans + ch * (ncP[r][rem] - ncP[l-1][rem])) % mod;
            if (ans < 0) {
                ans += mod;
            }
        }
    }
    cout << ans << '\n';
}