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

lli fact[MAXC], Ifact[MAXC];

struct event {
    int X, in, ty;
    event(int a, int b, int c) : X(a), in(b), ty(c) {}
    bool operator<(event &r) {
        return make_pair(X, ty) < make_pair(r.X, r.ty);
    }
};

lli modp(int n, int p) {
    if (!p) {
        return 1;
    } else if (p & 1) {
        return modp(n, p - 1) * n % mod;
    } else {
        lli t = modp(n, p >> 1);
        return t * t % mod;
    }
}

lli ncr(int n, int r) {
    if (n < r) {
        return 0;
    }
    lli ans = Ifact[r] * Ifact[n-r] % mod;
    return ans * fact[n] % mod;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = Ifact[0] = 1;
    for (int i = 1; i < MAXC; i++) {
        fact[i] = fact[i-1] * i % mod;
        Ifact[i] = modp(fact[i], mod - 2);
    }

    int n, k;
    cin >> n >> k;
    vector< event > E;
    for(int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        E.pb(l, i, -1);
        E.pb(r, i, 1);
    }
    sort(E.begin(), E.end());
    int cnt = 0;
    lli ans = 0;
    for (auto &x : E) {
        cnt -= x.ty;
        if (x.ty == 1) {
            ans = (ans + ncr(cnt, k - 1)) % mod;   
        }
    }
    cout << ans << '\n';
}