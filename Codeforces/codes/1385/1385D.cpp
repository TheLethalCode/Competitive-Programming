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
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int dp[MAXC][20], n, x;

int solve(int l, int i){
    if(i==0){
        return dp[l][i];
    }
    if(i==1){
        return min(dp[l][i] + dp[l+1][i-1], dp[l+1][i] + dp[l][i-1]);
    }
    i--;
    int a = dp[l][i+1] + solve(l+(1<<i), i);
    int b = dp[l+(1<<i)][i+1] + solve(l, i);
    return min(a, b);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> n >> s;
        x = log2(n);
        FOR(i, n+1){
            FOR(j, x+1){
                dp[i][j] = -1;
            }
        }
        char cur = 'a';
        for(int i=x-1;i>=0;i--){
            for(int j=0;j<n;j+=1<<i){
                int cnt = 0;
                for(int k=j;k < (j+(1<<i));k++){
                    cnt += (s[k]!=cur);
                }
                dp[j][i+1] = cnt;
            }
            cur++;
        }
        for(int j=0;j<n;j++){
            dp[j][0] = (s[j]!=cur);
        }
        cout << solve(0, x) << '\n';
    }
}