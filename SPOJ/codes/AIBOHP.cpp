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
        string s;
        cin>>s;
        int r=s.length();
        int dp[r+1][r+1];
        for(int i=0;i<=r;i++)
            for(int j=0;j<=r;j++)
                dp[i][j]=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=r;j++)
            {
                if(s[i-1]==s[r-j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<r-dp[r][r]<<endl;
    }
}