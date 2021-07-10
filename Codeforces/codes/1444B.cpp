#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 998244353 
#define lli long long
#define fi first
#define se second
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define C1 200005
#define C2 2005

lli modp(int n, int p) {
    if (!p) {
        return 1;
    } else if (p & 1) {
        return n * modp(n, p - 1) % mod;
    } else {
        lli t = modp(n, p >> 1);
        return t * t % mod;
    }
}

lli fact(int n) {
    return n == 1? 1: fact(n - 1) * n % mod;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector< int > v(2*n);
    lli sum = 0;
    for (int &x: v) {
        cin >> x;
        sum += x;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        sum -= 2 * v[i];
    }
    sum %= mod;
    sum = sum * fact(2*n) % mod;
    sum = sum * modp(fact(n), mod - 2) % mod;
    sum = sum * modp(fact(n), mod - 2) % mod;
    cout << sum << "\n";
}