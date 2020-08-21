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
#define MAXC 20005
// %

int val[55][MAXC], sum[55][MAXC];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    FOR (i, n) {
        FOR (j, m) {
            cin >> val[i+1][j+1];
            sum[i+1][j+1] = sum[i+1][j] + val[i+1][j+1]; 
        }
    }
    int dp[n+2][m+2], pref[m+2], suff[m+2];
    memset(dp, 0, sizeof(dp));
    memset(pref, 0, sizeof(pref));
    memset(suff, 0, sizeof(suff));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - k + 1; j++) {
            dp[i][j] = sum[i][j+k-1] - sum[i][j-1] + sum[i+1][j+k-1] - sum[i+1][j-1];
            int temp = suff[j+k];
            if (j - k >= 1) {
                temp = max(temp, pref[j-k]);
            }
            for (int r = max(1, j-k+1); r <= min(m-k+1, j+k-1); r++) {
                int lo = max(r, j), hi = min(j+k-1, r+k-1);
                temp = max(temp, dp[i-1][r] - sum[i][hi] + sum[i][lo-1]);
            }
            dp[i][j] += temp;
        }
        for (int j = 1; j <= m - k + 1; j++) {
            pref[j] = max(pref[j-1], dp[i][j]);
        }
        for (int j = m - k + 1; j >= 1; j--) {
            suff[j] = max(suff[j+1], dp[i][j]);
        }
    }
    cout << suff[1] << '\n';
}