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
#define MAXC 2005
// %

int n, ar[2*MAXC], ma[2*MAXC], pos[2*MAXC];
int dp[MAXC][MAXC];

int solve(int i, int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(!i && !j){
        return dp[i][j] = 1;
    }
    int p = pos[ma[i+j]];
    if(i+j-p+1 > max(i, j)){
        return dp[i][j] = 0;
    }
    else if(i+j-p+1 > i){
        return dp[i][j] = solve(i, j - (i+j-p+1));
    }
    else if(i+j-p+1 > j){
        return dp[i][j] = solve(i - (i+j-p+1), j);
    }
    return dp[i][j] = solve(i - (i+j-p+1), j) | solve(i, j - (i+j-p+1));
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        FOR(i, 2*n){
            cin >> ar[i];
            ma[i+1] = max(ma[i], ar[i]);
            pos[ar[i]] = i+1; 
        }
        FOR(i, n+1){
            FOR(j, n+1){
                dp[i][j] = -1;
            }
        }
        cout << (solve(n, n)? "YES": "NO") << '\n';
    }
}