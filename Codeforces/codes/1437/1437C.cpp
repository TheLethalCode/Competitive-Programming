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

int dp[205][405];

int solve(int i, int m, vector< int > &v) {
    if (dp[i][m] != -1) {
        return dp[i][m];
    }
    if(m == 0) {
        return dp[i][m] = mod;
    }
    if(i == 0) {
        return dp[i][m] = min(abs(v[0] - m), solve(0, m-1, v));
    }
    return dp[i][m] = min(abs(v[i] - m) + solve(i-1, m-1, v), solve(i, m-1, v));
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector< int > v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 2*n; j++) {
                dp[i][j] = -1;
            }
        }
        cout << solve(n-1, 2*n, v) << '\n';
    }
}