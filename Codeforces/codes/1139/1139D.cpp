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
vector < int > fact[MAXC], prime;
int pri[MAXC];

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

// number of integers from 1 to m, co prime with n
int F(int n, int m) {
    vector< int > pf;
    int ans = m;
    while (n != 1) {
        int x = pri[n];
        pf.pb(x);
        while (n % x == 0) {
            n /= x;
        }
    }
    int x = pf.size();
    for (int i = 1; i < (1<<x); i++) {
        int lcm = 1, ch = -1;
        for (int j = 0; j < x; j++) {
            if (i & 1<<j) {
                lcm = lcm * pf[j] / __gcd(lcm, pf[j]);
                ch *= -1;
            }
        }
        ans -= ch * m / lcm;
    }
    return ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < MAXC; i++) {
        for (int j = 2 * i; j < MAXC; j+=i) {
            fact[j].pb(i);
        }
    }
    for (int i = 2; i < MAXC; i++) {
        if (!pri[i]) {
            pri[i] = i;
            prime.pb(i);
        }
        for (int j = 0; j < prime.size() && prime[j] <= pri[i] && i*prime[j] < MAXC; j++) {
            pri[i * prime[j]] = prime[j];
        } 
    }
    int m;
    cin >> m;
    lli dp[m+1] = {}, ans = 0;
    for (int i = 2; i <= m; i++) {
        lli temp = m;
        FORR (y, fact[i]) {
            temp = (temp + dp[y] * F(i/y, m/y)) % mod;
        }
        dp[i] = temp * modp(m - m / i, mod - 2) % mod;
        ans = (ans + dp[i] + 1) % mod;
    }
    cout << (ans + 1) * modp(m, mod-2) % mod << '\n';
}