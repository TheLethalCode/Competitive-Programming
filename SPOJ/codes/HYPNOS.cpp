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

vi dp(81*9+2,0);

int fl=1;

int sum(lli r)
{
    int ans=0;
    while(r)
        ans+=(r%10)*(r%10),r/=10;
    return ans;
}

int calc(int x)
{
    if(x==1)
        return 0;
    if(dp[x])
    {
        fl=0;
        return 0;
    }
    dp[x]=1;
    return 1+calc(sum(x));
}

int main()
{
    crap;
    lli t;
    cin>>t;
    int ans=calc(sum(t));
    if(!fl)
        cout<<-1;
    else
        cout<<ans+1;
    cout<<endl;
}