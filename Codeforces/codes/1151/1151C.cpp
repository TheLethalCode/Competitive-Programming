#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back
#define pp pop_back

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
vli num(63,0);

lli tot(lli x)
{
    int nu = log2(x);
    lli o, e;
    if(nu & 1)
    {
        e = x-(1LL<<nu)+1;
        if(nu>1)
            e+=num[nu-2];
        e%=mod;
        o = num[nu-1];
    }
    else
    {
        o = x-(1LL<<nu)+1;
        if(nu>0)
            o+=num[nu-2];
        o%=mod;
        e = num[nu-1];
        if(nu-1 < 0)
            e=0;
    }
    // cout<<o<<" "<<e<<endl;
    return ((o*o)%mod + (e*e)%mod+e)%mod;
}

int main(int argc, char **argv)
{
    crap;
    // cout<<tot(1)<<endl;
    lli temp=4;
    num[0]=1, num[1]=2;
    for(int i=2;i<=62;i++)
        num[i]=num[i-2]+temp, num[i]%=mod, temp*=2;
    
    lli l, r;
    cin>>l>>r;
    if(l==1)
        cout<<tot(r);
    else
        cout<<(tot(r)-tot(l-1)+mod)%mod<<endl;
}