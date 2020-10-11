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
        lli  t = modp(n, p >> 1);
        return t * t % mod;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector < lli > fact(MAXC, 1), Ifact(MAXC, 1);
    for (int i = 2; i < MAXC; i++) {
        fact[i] = fact[i-1] * i % mod;
        Ifact[i] = modp(fact[i], mod - 2);
    }
    while (t--) {
        int n;
        cin >> n;
        map< int, int, greater< int > > cnt;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            cnt[x]++;
        }
        lli ans = modp(2, n), touche = cnt.begin()->se;
        if (!(touche & 1)) {
            lli rem = modp(2, n - touche) * fact[touche] % mod;
            rem = rem * modp(Ifact[touche >> 1], 2) % mod;
            ans -= rem;
            if (ans < 0) {
                ans += mod;
            }
        }
        cout << ans << '\n';
    }
}