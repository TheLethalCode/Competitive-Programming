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
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %

int main(int argc, char **argv)
{
    crap;
    int n, m, ok=0;
    lli ans = 0;
    cin>>n>>m;
    vli r(n), c(m);
    FOR(i, n) cin>>r[i];
    FOR(j, m) cin>>c[j];
    sort(all(r)), sort(all(c));
    FOR(i, n) ans+=r[i]*m;
    FOR(j, m) ans+=-r[n-1]+c[j], ok|=(r[n-1]==c[j]);
    if(!ok) ans+=r[n-1]-r[n-2];
    if(c[0] < r[n-1]) ans=-1;
    cout<<ans<<endl;
}