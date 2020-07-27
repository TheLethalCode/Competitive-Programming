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
    int t,te=0;
    cin>>t;
    while(te++<t)
    {
        lli n,ans=0;
        cin>>n;
        vi v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        lli dp[n][2];
        if(n==1)
            ans=v[0];
        else if(n==2)
            ans=max(v[0],v[1]);
        else if(n>=3)
        {
            dp[0][1]=v[0];
            dp[0][0]=0;
            dp[1][1]=v[1];
            dp[1][0]=v[0];
            for(int i=2;i<n;i++)
            {
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                dp[i][1]=max(v[i]+dp[i-2][1],dp[i-1][0]+v[i]);
            }
            ans=max(dp[n-1][0],dp[n-1][1]);
        }
        cout<<"Case "<<te<<": "<<ans<<endl;
    }
}