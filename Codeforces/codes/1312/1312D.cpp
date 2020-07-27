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

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %

lli modp(lli n, lli p)
{
    if(!p) return 1;
    if(p & 1) return (n * modp(n,p-1)) % mod;
    lli t = modp(n, p/2);
    return (t*t)%mod;
}

lli modinv(lli n)
{
    return modp(n, mod-2);
}

int main(int argc, char **argv)
{
    crap;
    int n, m;
    cin>>n>>m;
    vli mult(m+1,1);
    for(int i=1;i<=m;i++)
        mult[i] = mult[i-1] * i, mult[i] %= mod;
    lli ans = 0;
    for(int i = 2;i<=n-1;i++)
    {
        lli temp = mult[n-2] * modinv(mult[i-2]);
        temp %= mod;
        temp *=  modinv(mult[n-i-1]), temp %= mod;
        ans += temp, ans %= mod;
    }
    lli temp = mult[m] * modinv(mult[n-1]);
    temp %= mod;
    temp *= modinv(mult[m-n+1]), temp %= mod;
    temp *= ans  , temp %= mod; 
    cout<<temp<<endl;
}   