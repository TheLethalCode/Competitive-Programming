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
    string s;
    cin>>n>>s;
    int dp[n][3];
    
    if(s[0] == 'B')
        dp[0][0] =0, dp[0][1] =1, dp[0][2] =1;
    else if(s[0] == 'G')
        dp[0][0] =1, dp[0][1] =0, dp[0][2] =1;
    else
        dp[0][0] =1, dp[0][1] =1, dp[0][2] =0;

    for(int i=1;i<n;i++)
    {
        if(s[i] == 'G')
        {
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+1;
            dp[i][2]=min(dp[i-1][1],dp[i-1][0])+1;
        }
        else if(s[i] == 'B')
        {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
            dp[i][2]=min(dp[i-1][1],dp[i-1][0])+1;
        }
        else
        {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+1;
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
            dp[i][2]=min(dp[i-1][1],dp[i-1][0]);
        }
    }
    string ans="";
    if(dp[n-1][0] <= dp[n-1][1] && dp[n-1][0] <= dp[n-1][2])
        ans="B";
    else if(dp[n-1][1] <= dp[n-1][0] && dp[n-1][1] <= dp[n-1][2])
        ans="G";
    else
        ans="R";
    for(int i=1;i<n;i++)
    {
        if(ans[i-1] == 'B')
        {
            if(s[n-i] == 'B' && dp[n-1-i][1] == dp[n-i][0])
                ans+="G";
            else if(s[n-i] == 'B' && dp[n-1-i][2] == dp[n-i][0])
                ans+="R";
            else if(s[n-i] != 'B' && dp[n-1-i][2]+1 == dp[n-i][0])
                ans+="R";
            else if(s[n-i] != 'B' && dp[n-1-i][1]+1 == dp[n-i][0])
                ans+="G";
        }
        if(ans[i-1] == 'G')
        {
            if(s[n-i] == 'G' && dp[n-1-i][0] == dp[n-i][1])
                ans+="B";
            else if(s[n-i] == 'G' && dp[n-1-i][2] == dp[n-i][1])
                ans+="R";
            else if(s[n-i] != 'G' && dp[n-1-i][2]+1 == dp[n-i][1])
                ans+="R";
            else if(s[n-i] != 'G' && dp[n-1-i][0]+1 == dp[n-i][1])
                ans+="B";
        }
        if(ans[i-1] == 'R')
        {
            if(s[n-i] == 'R' && dp[n-1-i][1] == dp[n-i][2])
                ans+="G";
            else if(s[n-i] == 'R' && dp[n-1-i][0] == dp[n-i][2])
                ans+="B";
            else if(s[n-i] != 'R' && dp[n-1-i][0]+1 == dp[n-i][2])
                ans+="B";
            else if(s[n-i] != 'R' && dp[n-1-i][1]+1 == dp[n-i][2])
                ans+="G";
        }
    }
    cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<endl;
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}