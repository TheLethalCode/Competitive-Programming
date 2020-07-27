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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

lli pomo(lli n, lli p){
    if(!p) return 1;
    if(p&1) return (pomo(n, p-1)*n)%mod;
    lli t = pomo(n, p>>1);
    return (t*t)%mod;
}

int main(int argc, char **argv)
{
    crap;
    int n;
    lli val = 0;
    cin>>n;
    vi v(n);
    FOR(i, n) cin>>v[i];
    FOR(i, n) val = ((1 + val)*pomo(v[i], mod-2))%mod, val=(val*100)%mod;
    cout<<val<<endl;
}