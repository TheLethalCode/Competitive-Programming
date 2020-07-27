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
    vector< string > v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector< vi > dp(m,vi(n));
    for(int i=0;i<n;i++)
    {
        int j=0;
        while(j<m)
        {
            int cur=j;
            while(cur<m && v[i][cur]=='1')
                cur++;
            while(cur-j)
                dp[j][i]=cur-j,j++;
            if(j!=m)
                dp[j][i]=0;
            j++;
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        sort(dp[i].begin(),dp[i].end());
        for(int j=0;j<n;j++)
            ans=max(ans,(n-j)*dp[i][j]);
    }
    cout<<ans<<endl;
}