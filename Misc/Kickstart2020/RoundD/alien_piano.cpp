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
#define sz(a) (int)(a.size())
#define MAXC 10005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int k, ar[MAXC], ans = 0;

void solve(){
    int dp[k][4];
    FOR(i, 4){
        dp[k-1][i] = 0;
    }
    for(int i=k-2;i>=0;i--){
        FOR(x, 4){
            dp[i][x] = 1e6;
            FOR(y, 4){
                int ok = 0;
                if(ar[i] < ar[i+1] && x < y){
                    ok = 1;
                }
                if(ar[i] > ar[i+1] && x > y){
                    ok = 1;
                }
                if(ar[i] == ar[i+1] && x == y){
                    ok = 1;
                }
                dp[i][x] = min(dp[i][x], dp[i+1][y] + !ok);
            }
        }
    }
    FOR(i, 4){
        ans = min(ans, dp[0][i]);
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int z=1; z<=t; z++){
        cin >> k;
        ans = 1e6;
        FOR(i, k){
            cin >> ar[i];
        }
        solve();
        cout << "Case #" << z << ": " << ans << '\n';
    }
}