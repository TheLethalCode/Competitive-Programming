#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    int n,m;
    cin>>n>>m;
    vector< vi > v(n+1,vi(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>v[i][j];
    
    vector< vector< vli > > dp(4,vector< vli >(n+2,vli(m+2,0)));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[0][i][j]=v[i][j]+max(dp[0][i-1][j],dp[0][i][j-1]);
    
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            dp[1][i][j]=v[i][j]+max(dp[1][i-1][j],dp[1][i][j+1]);
    
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
            dp[3][i][j]=v[i][j]+max(dp[3][i+1][j],dp[3][i][j+1]);
    
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
            dp[2][i][j]=v[i][j]+max(dp[2][i+1][j],dp[2][i][j-1]);

    lli ans=0;
    for(int i=2;i<n;i++)
        for(int j=2;j<m;j++)
        {
            // cout<<dp[1][i][j-1]<<endl;
            ans=max(ans,dp[0][i-1][j]+dp[3][i+1][j]+dp[2][i][j-1]+dp[1][i][j+1]);
            ans=max(ans,dp[0][i][j-1]+dp[3][i][j+1]+dp[2][i+1][j]+dp[1][i-1][j]);
        }
    cout<<ans<<endl;
}