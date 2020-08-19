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
        return modp(n, p-1) * n % mod;
    } else {
        lli t = modp(n, p >> 1);
        return t * t % mod;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli x, k;
    cin >> x >> k;
    if (x == 0) {
        cout << 0 << '\n';
        return 0;
    }
    lli ans = (x % mod) * modp(2, k + 1) % mod;
    ans = ans - (modp(2, k) - 1);
    cout << (ans + mod) % mod << '\n';
}