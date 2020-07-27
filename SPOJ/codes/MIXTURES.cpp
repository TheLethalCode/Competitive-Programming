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

vi sum;

int smoke(int i,int k,int j)
{
    return ((sum[k+1]-sum[i])%100)*((sum[j+1]-sum[k+1])%100);
}

int main()
{
    crap;
    int n;
    while(cin>>n)
    {
        vi v(n);
        sum.clear();
        sum.resize(n+1,0);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+v[i-1];
        vector< vi > dp(n,vi(n,0));
        for(int l=1;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int ans=1e9,j=i+l-1;
                for(int k=i;k<j;k++)
                {
                    ans=min(ans,dp[i][k]+dp[k+1][j]+smoke(i,k,j));
                }
                if(l!=1)
                    dp[i][j]=ans;
            }
        }
        cout<<dp[0][n-1]<<endl;
    }    
}