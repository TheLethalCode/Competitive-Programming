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
        int p,f;
        cin>>p>>f;
        int w=f-p;
        int n;
        cin>>n;
        vector< pa > v(n);
        for(int i=0;i<n;i++)
            cin>>v[i].fi>>v[i].se;
        
        int dp[10001];
        for(int i=0;i<=10000;i++)
            dp[i]=1e9;
        dp[0]=0;
        for(int i=0;i<w;i++)
        {
            for(auto r:v)
            {
                if(r.se+i>w)
                    continue;
                dp[i+r.se]=min(dp[i+r.se],dp[i]+r.fi);
            }
        }
        if(dp[w] == 1e9)
            cout<<"This is impossible.";
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[w]<<".";
        cout<<endl;
    }
}