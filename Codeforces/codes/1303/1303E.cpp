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
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
string s;
bool solve(string t1, string t2){
    int n = sz(s), x = sz(t1), y = sz(t2);
    int dp[n+1][x+1];
    t1 += '#';
    t2 += '#';
    FOR(i, n+1){
        FOR(j, x+1){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    FOR(i, n){
        FOR(j, x+1){
            if(dp[i][j]!=-1){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                if(s[i] == t1[j]){
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
                }
                if(s[i] == t2[dp[i][j]]){
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 1);
                }
            }
        }
    }
    return (dp[n][x] == y);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int ok = 0;
        string z;
        cin >> s >> z;
        FOR(i, sz(z)){
            if(solve(z.substr(i), z.substr(0, i))){
                ok = 1;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}