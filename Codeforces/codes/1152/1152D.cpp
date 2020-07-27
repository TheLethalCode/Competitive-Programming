#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %

lli dp[2001][2001], ans=0;

lli solve(int i, int j){
    if(dp[i][j]!=-1) return dp[i][j];
    if(!i) return dp[i][j]=(j==0);
    if(!j) return dp[i][j]=solve(i-1, j+1);
    if(j==i) return dp[i][j]=solve(i-1, j-1);
    return dp[i][j]=(solve(i-1, j+1)+solve(i-1,j-1))%mod;
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    FOR(i, 2*n+1) FOR(j, 2*n+1) dp[i][j]=-1;
    solve(2*n, 0);
    for(int i=2*n-1;i>=1;i-=2){
        for(int j=0;j<=n;j++){
            if(dp[i][j]==-1) continue;
            ans = (ans + dp[i][j]) % mod;
        }
    }
    cout<<ans<<endl;
}