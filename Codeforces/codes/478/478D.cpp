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

int sume(int h)
{
    return h*(h+1)/2;
}

int main()
{
    crap;
    int r,g;
    cin>>r>>g;
    int sum=r+g;
    if(r>g)
        r=g,g=sum-g;
    int h=(sqrt(8*sum+1)-1)/2;
    vector< vli > v(2,vli(r+1,0));
    v[0][0]=1;
    for(int i=1;i<=h;i++)
    {
        int te=min(sume(i),r);
        for(int j=0;j<=te;j++)
        {
            int k=sume(i)-j;
            if(k>=i && k<=g)
                v[1][j]+=v[0][j];
            if(j>=i)
                v[1][j]+=v[0][j-i];
            v[1][j]%=mod;
        }
        v[0]=v[1];
        v[1].assign(r+1,0);
    }
    lli ans=0;
    for( int a : v[0])
        ans+=a,ans%=mod; 
    cout<<ans<<endl;
}