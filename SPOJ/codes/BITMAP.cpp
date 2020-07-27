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

bool isval(int i,int j,int n,int m)
{
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}

int main()
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector< string > v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        queue< pa > q;
        int dp[n][m],vin[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                dp[i][j]=1e9,vin[i][j]=0;
                if(v[i][j] == '1')
                    q.push({i,j}),dp[i][j]=0,vin[i][j]=1;
            }
        while(!q.empty())
        {
            pa l = q.front();
            q.pop();
            for(int i=l.fi-1;i<=l.fi+1;i++)
                for(int j=l.se-1;j<=l.se+1;j++)
                {
                    if(abs(i-l.fi) + abs(j-l.se)!=1 || vin[i][j] || !isval(i,j,n,m))
                        continue;
                    dp[i][j]=min(dp[i][j],dp[l.fi][l.se]+1);
                    vin[i][j]=1;
                    q.push({i,j});
                }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
    }
}