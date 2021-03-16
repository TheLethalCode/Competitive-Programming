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
#define MAXC 1000005
// %

lli dp[MAXC][2];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lli n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vector< lli > v(n), le(n), fi(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        le[i] = min(r1*(v[i] + 1), r2);
        fi[i] = r1*v[i] + r3;
    }
    dp[0][0] = le[0];
    dp[0][1] = fi[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][1] + le[i];
        dp[i][1] = 2*d + (r1+dp[i-1][0]) + min(le[i]+r1, fi[i]);
        dp[i][1] = min(dp[i][1], dp[i-1][1] + min(fi[i], le[i]+2*d+r1));
    }
    cout << (n-1)*d + min(dp[n-1][1], (r1+dp[n-2][0]) + (fi[n-1]+d)) << "\n";
}