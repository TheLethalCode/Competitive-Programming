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
    int b,n;
    cin>>b>>n;
    while(n)
    {
        vector< pa > v(n);
        for(int i=0;i<n;i++)
            cin>>v[i].fi>>v[i].se;
        vector< vi > dp(n+1,vi(b+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=b;j++)
            {
                dp[i][j] = dp[i-1][j];
                if( j >= v[i-1].fi)
                    dp[i][j] = max(dp[i][j],dp[i-1][j-v[i-1].fi] + v[i-1].se);
            }
        }
        int i=1;
        while( dp[n][i] != dp[n][b])
            i++;
        cout<<i<<" "<<dp[n][i]<<endl;
        cin>>b>>n;
    }
}