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

string s;
vector< int > to[MAXC];
lli temp;
int dp[MAXC][2];
int C[2];

void dfs(int u, int p = 0, int c = 0) {
    C[c]++;
    FORR (v, to[u]) {
        if (v != p) {
            dfs(v, u, !c);
        }
    }
}

void solve(int u, int p, int c) {
    dp[u][0] = dp[u][1] = 0;
    FORR (v, to[u]) {
        if (v != p) {
            solve(v, u, !c);
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][1];
        }
    }
    temp += dp[u][0] + dp[u][1];
    if (s[u-1] - '0' != c) {
        dp[u][c]++;
    }
    lli cap = min(dp[u][0], dp[u][1]);
    dp[u][0] -= cap;
    dp[u][1] -= cap;
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
        FOR (i, n) {
            to[i+1].clear();
        }
        C[0] = C[1] = 0;
        FOR (i, n-1) {
            int x, y;
            cin >> x >> y;
            to[x].pb(y);
            to[y].pb(x);
        }
        cin >> s;
        int col[2] = {};
        FORR (v, s) {
            col[v-'0']++;
        }
        dfs(1);
        if (col[0] != C[0] && col[1] != C[0]) {
            cout << "-1\n";
            continue;
        }
        lli ans = 1e18;
        if (col[0] == C[0]) {
            solve(1, 0, 0);
            ans = min(ans, temp);
            temp = 0;
        }
        if (col[0] == C[1]) {
            solve(1, 0, 1);
            ans = min(ans, temp);
            temp = 0;
        }
        cout << ans << '\n';
    }
}