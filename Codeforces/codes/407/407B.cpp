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
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    lli ans=0;
    vli dp(n,0);
    for(int i=0;i<n;i++)
    {
        dp[i]++;
        for(int j=v[i]-1;j<i;j++)
            dp[i]+=dp[j]+1;
        dp[i]%=mod;
    }
    for(int i=0;i<n;i++)
        ans+=dp[i]+1,ans%=mod;
    cout<<ans<<endl;
}