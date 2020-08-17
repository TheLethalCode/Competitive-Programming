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

int solve(string &s) {
    int n = s.length(), dp[n][2][2];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][s[0]-'0'][s[1]-'0'] = 0;
    for (int i = 2; i < n; i++) {
        FOR (j, 2) {
            FOR (k, 2) {
                FOR (l, 2) {
                    if (j!=k || k!=l) {
                        dp[i][k][l] = min(dp[i][k][l], dp[i-1][j][k] + (s[i]!=l+'0'));
                    }
                }
            }
        }
    }
    int ans = mod, a = s[0]-'0', b = s[1] - '0';
    FOR (j, 2) {
        FOR (k, 2) {
            if ((b!=a || a!=k) && (a!=k || j!=k)) {
                ans = min(ans, dp[n-1][j][k]);
            }
        }
    }
    return ans;
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
        string s;
        cin >> s;
        FOR (i, n) {
            s[i] = (s[i] == 'R')? '1': '0';
        }
        int ans = mod;
        FOR (i, 2) {
            FOR (j, 2) {
                string temp = s;
                temp[0] = i + '0', temp[1] = j + '0';
                ans = min(ans, solve(temp) + (s[0]!=i+'0') + (s[1]!=j+'0'));
            }
        }
        cout << ans << '\n';
    }
}