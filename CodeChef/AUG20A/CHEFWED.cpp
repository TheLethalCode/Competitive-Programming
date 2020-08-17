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
#define MAXC 1005
// %

int n, k;
int dp[MAXC], val[MAXC][MAXC];

int solve(int i) {
    if (dp[i] != -1) {
        return dp[i];
    }
    int cur = val[0][i] + k;
    for (int j = 0; j < i; j++) {
        cur = min(cur, solve(j) + k + val[j+1][i]);
    }
    return dp[i] = cur;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector < int > v(n);
        FOR (i, n) {
            cin >> v[i];
        }
        memset(dp, 0xff, sizeof(dp));
        for (int i = 0; i < n; i++) {
            vector < int > temp(101, 0);
            for (int j = i, whi = 0; j < n; j++) {
                temp[v[j]]++;
                whi += (temp[v[j]]>=2) + (temp[v[j]]==2);
                val[i][j] = whi;
            }
        }
        cout << solve(n-1) << '\n';
    }
}