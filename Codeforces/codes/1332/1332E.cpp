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
#define mp make_pair

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %

lli pomo(lli n, lli p){
    if(!p) return 1;
    if(p&1) return (pomo(n, p-1)*n)%mod;
    lli t = pomo(n, p>>1);
    return(t*t)%mod;
}

int main(int argc, char **argv)
{
    crap;
    lli n, m, L, R, odd=0, even=0, ans=0;
    cin>>n>>m>>L>>R;
    
    odd = (R-L+1)/2 + ((R&1) && (L&1)), even = R-L+1-odd;
    ans = pomo(even+odd, n*m); 
    if(!((n*m)&1)){
        ans += pomo(even-odd, n*m) + mod, ans %= mod;
        ans *= pomo(2, mod-2), ans %= mod;
    }
    cout<<ans<<endl;
}