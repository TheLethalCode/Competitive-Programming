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
    lli n,b;
    cin>>n>>b;
    lli ans=0,cnt=0;
    vector< pair< lli, lli > > v;
    for(int i=2; i<= sqrt(b);i++)
    {
        int count=0;
        if(b%i)
            continue;
        while(b%i==0)
            b/=i,count++;
        v.push_back({i,count});
    }
    if(b!=1)
        v.push_back({b,1});
    lli val=1e18;
    for(auto p:v)
    {
        lli sum=0,temp=p.fi;
        ans=p.fi;
        while(n/ans >= temp)
            sum+=n/ans,ans*=temp;
        sum+=n/ans;
        val=min(val,sum/p.se);
    }
    cout<<val<<endl;
}