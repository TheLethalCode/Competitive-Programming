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


lli dp[21][21][21];

lli solve(int s1, int s2, int n){
    if (dp[s1][s2][n] != -1) {
        return dp[s1][s2][n];
    }
    if (!n) {
        return dp[s1][s2][n] = !s1 && !s2;
    }
    lli ans = 0;
    for (int i = 0; i <= s1; i++) {
        for (int j = 0; j <= s2; j++) {
            ans = (ans + solve(s1 - i, s2 - j, n-1)) % mod;
        }
    }
    return dp[s1][s2][n] = ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    memset(dp, 0xff, sizeof(dp));
    while (t--) {
        int n, rx, ry;
        cin >> n >> rx >> ry;
        cout << solve(rx, ry, n) << '\n';
    }
}