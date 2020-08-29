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
        lli t = modp(n, p >> 1);
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
        int n, m;
        cin >> n >> m;
        vector < int > dis(n);
        for (int i = 1, x; i < n; i++) {
            cin >> x;
            dis[x]++;
        }
        dis[0] = 1;
        lli totC = 0, ans = 1;
        for (int i = 1; i < n; i++) {
            totC += 1LL * dis[i] * (dis[i] - 1)/2;
        }
        for (int i = 1; i < n; i++) {
            if (dis[i]) {
                ans = ans * modp(dis[i-1], dis[i]) % mod;
            }
        }
        int rem = m - n + 1;
        ans = ans * Ifact[rem] % mod;
        if (rem < 0 || totC < rem) {
            cout << "0\n";
            continue;
        }
        for (lli tot = totC; tot > totC - rem; tot--) {
            ans =  ans * tot % mod;
        }
        cout << ans << endl;
    }
}