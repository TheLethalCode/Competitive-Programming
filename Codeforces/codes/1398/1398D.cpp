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
#define MAXC 205
// %

lli dp[MAXC][MAXC][MAXC];
vector< int > v[3];

lli solve(int a1, int a2, int a3){
    if (dp[a1][a2][a3] != -1) {
        return dp[a1][a2][a3];
    }
    int x = 0, y = 0, z = 0;
    if (a2 && a3) {
        x = solve(a1, a2-1, a3-1) + v[1][a2-1]*v[2][a3-1];
    }
    if (a1 && a3) {
        y = solve(a1-1, a2, a3-1) + v[0][a1-1]*v[2][a3-1];
    }
    if (a1 && a2) {
        z = solve(a1-1, a2-1, a3) + v[1][a2-1]*v[0][a1-1];
    }
    return dp[a1][a2][a3] = max(x, max(y, z));
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n[3];
    FOR(i, 3) {
        cin >> n[i];
    }
    FOR(i, 3) {
        v[i].resize(n[i]);
        FOR(j, n[i]){
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end());
    }
    memset(dp, 0xff, sizeof(dp));
    cout << solve(n[0], n[1], n[2]) << '\n';
}