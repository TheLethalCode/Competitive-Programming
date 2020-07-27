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

pa red(string r)
{
    string te="";
    for(auto k:r)
    {
        if(te == "")
            te += k;
        else if(te.back() == '{' && k == '}')
            te.pop_back();
        else
            te += k;
    }
    int i=0,j=0;
    while(i < te.length() && te[i] == '}')
        i++;
    while(i + j < te.length() && te[i+j] == '{')
        j++;
    return {i,j};
}

int main()
{
    crap;
    int t=1;
    string s;
    cin>>s;
    while(s[0] != '-')
    {
        pa val = red(s);
        int x=val.fi,y=val.se;
        int dp[val.fi+1][val.se+1];
        for(int i=0;i<x+1;i+=2)
            dp[i][0]=i/2;
        for(int j=0;j<=y;j+=2)
            dp[0][j]=j/2;
        for(int i=1;i<=x;i++)
        {
            for(int j = (i%2 != 0)?1:2 ; j <= y ;j+=2)
            {
                dp[i][j] = dp[i-1][j-1]+2;
                if(i >= 2)
                    dp[i][j] = min(dp[i-2][j]+1,dp[i][j]);
                if(j >= 2)
                    dp[i][j] = min(dp[i][j],dp[i][j-2]+1);
            }
        }
        cout<<t<<". "<<dp[x][y]<<endl;
        cin>>s;
        t++;
    }
}