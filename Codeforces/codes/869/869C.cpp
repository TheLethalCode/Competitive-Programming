#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
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

vli fac(5001,1);

lli modp(lli n, int p)
{
    if(!p)
        return 1;
    if(p & 1)
        return (modp(n, p-1)*n)%mod;
    lli t = modp(n, p>>1);
    return (t*t)%mod;
}

lli ncr(int n, int r)
{
    lli ans = fac[n]*modp(fac[r], mod-2);
    ans %= mod, ans*= modp(fac[n-r], mod-2), ans %=mod;
    return ans;
}

lli ont(lli x, lli y)
{
    lli ans = 0;
    for(int i=0;i<=x;i++)
    {
        lli tem = ncr(x,i)*ncr(y,i);
        tem %= mod, tem*=fac[i], tem%=mod;
        ans+=tem, ans %= mod;
    }
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    int a, b, c;
    cin>>a>>b>>c;
    for(int i=1;i<=5000;i++)
        fac[i] = fac[i-1]*i, fac[i] %= mod;
    lli ans = ont(min(a,b), max(a,b));
    ans*=ont(min(b,c), max(b,c)), ans%= mod;
    ans*=ont(min(a,c), max(a,c)), ans%= mod; 
    cout<<ans<<endl;
}