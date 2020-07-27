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
#define MAXC 1000005
#define INF mod
// %
int n, m, x, v[MAXC], dp[MAXC][3][3];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i, n){
        cin >> x;
        v[x]++;
    }
    // j - i-2, i-1, i
    // k - i-1, i, i+1
    // z - i, i+1, i+2
    for(int i=m;i>=1;i--){
        FOR(j, 3){
            FOR(k, 3){
                int rem = v[i]-j-k;
                dp[i][j][k] = -INF;
                FOR(z, 3){
                    dp[i][j][k] = max(dp[i][j][k], rem-z>=0?j+dp[i+1][k][z]+(rem-z)/3:-INF);
                }
            }
        }
    }
    cout << dp[1][0][0] << '\n';
}