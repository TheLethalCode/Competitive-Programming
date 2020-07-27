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
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        int n=a.length(), m=b.length();
        vector< vi > dp(n+1,vi(m+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0]=i;
        for(int i=0;i<=m;i++)
            dp[0][i]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j]= min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
            }
        }
        cout<<dp[n][m]<<endl;
    }
}