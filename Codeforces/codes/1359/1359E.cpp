#include<bits/stdc++.h>
using namespace std;

#define mod  998244353
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
vli fac(5*1e5+1,1);

lli mopo(lli n, lli k){
    if(!k) return 1;
    if(k&1) return (mopo(n, k-1)*n)%mod;
    lli t = mopo(n, k>>1);
    return (t*t)%mod;
}

lli ncr(lli n, lli r){
    lli ans = fac[n];
    ans *= mopo(fac[n-r], mod-2), ans%=mod;
    ans *= mopo(fac[r], mod-2), ans%=mod;
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    FOR(i, 5*1e5)
        fac[i+1] = fac[i]*(i+1), fac[i+1] %= mod;

    int n, k;
    cin>>n>>k;
    lli ans = 0;
    for(int i=1;i<=n;i++){
        if(n/i-1 < k-1) break;
        lli temp = ncr(n/i-1, k-1);
        ans+=temp, ans%=mod;
    }
    cout<<ans<<endl;
}