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

lli dp[MAXC][4][4];
int n, cnt = 0;
string s;

inline void norm(lli &x) {
    if (x >= mod) {
        x -=  mod;
    }
}

void solve() {
    dp[0][0][0] = 1; 
    for (int i = 1; i <= n; i++) {

        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                dp[i][x][y] = dp[i-1][x][y];
            }
        }

        if (s[i-1] != '?') {
            for (int qnum = 0; qnum <= 3; qnum++) {
                dp[i][qnum][s[i-1]-'a'+1] += dp[i-1][qnum][s[i-1]-'a'];
                norm(dp[i][qnum][s[i-1]-'a'+1]);
            }
        } else {
            cnt++;
            for (int qnum = 1; qnum <= 3; qnum++) {
                for (int cnum = qnum; cnum <= 3; cnum++) {
                    dp[i][qnum][cnum] += dp[i-1][qnum-1][cnum-1];
                    norm(dp[i][qnum][cnum]);
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    solve();
    lli pow3k[cnt + 1], ans = 0;
    pow3k[0] = 1;
    // cout << dp[6][0][0] << " " << dp[6][0][1] << " " << dp[6][0][2] << " " << dp[6][0][3] << endl;  
    // cout << dp[6][1][0] << " " << dp[6][1][1] << " " << dp[6][1][2] << " " << dp[6][1][3] << endl;  
    for (int i = 1; i <= cnt; i++) {
        pow3k[i] = pow3k[i-1] * 3 % mod;
    }
    for (int j = 0; j <= 3; j++) {
        ans += dp[n][j][3] * pow3k[max(0, cnt - j)] % mod;
        norm(ans);
    }
    cout << ans << '\n';
}