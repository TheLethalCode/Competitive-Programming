#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 998244353
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
template <class T> inline bool chmin(T a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}
string s, t;
int n, m;
lli dp[3001][3001];

lli solve(int i, int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(!j){
        if(i >= m){
            return dp[i][j] = (1 + solve(i+1, 0)) % mod;
        }
        else if(s[i] == t[i]){
            return dp[i][j] = solve(i+1, 0);
        }
        else{
            return dp[i][j]=0;
        }
    }
    else if(j<m){
        if(i+j >= m || t[i+j] == s[i]){
            dp[i][j] = solve(i+1, j);
        }
        if(t[j-1] == s[i]){
            dp[i][j] += (dp[i][j]==-1?1:0) + solve(i+1, j-1);
        }
        if(dp[i][j] == -1){
            return dp[i][j]=0;
        }
        else{
            return dp[i][j] % mod;
        }
    }
    else{
        dp[i][j] = 2 * solve(i+1, m);
        if(s[i] == t[m-1]) {
            dp[i][j] += solve(i+1, m-1);
        }
        return dp[i][j] % mod;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>t;
    n = sz(s), m = sz(t);
    FOR(i, n+1){
        FOR(j, m+1){
            dp[i][j] = -1;
        }
    }
    FOR(j, m+1){
        dp[n][j] = (j==0);
    }
    lli ans = 0;
    FOR(i, m+1){
        ans += solve(0, i);
    }
    cout<< ans % mod <<endl;
}