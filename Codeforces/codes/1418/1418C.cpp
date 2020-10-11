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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < int > v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int dp[n+5][2];
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        // j = 0 my friedns turn
        for (int i = 0; i < n; i++) {
            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + v[i]);
            dp[i+2][1] = min(dp[i+2][1], dp[i][0] + v[i] + v[i+1]);
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
            dp[i+2][0] = min(dp[i+2][0], dp[i][1]);
        }
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
}