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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %

int main(int argc, char **argv)
{
    crap;
    int n, k, x, ma=0, y=0;
    cin>>n>>k;
    vi a(n+1), b(n), fin(n);
    vpa pos;
    FOR(i, n) cin>>x, a[x]=i;
    FOR(i, n) cin>>b[i], pos.pb({b[i], i});
    sort(all(pos), [&](pa l, pa r){ return a[l.fi]<a[r.fi];});
    FORR(x, pos) {
        fin[x.se] = max(ma, x.se);
        ma = max(ma, x.se);
    }
    string ans(n,' ');
    FOR(i, n) {
        int la = fin[i];
        while(i<=la) ans[b[i]-1] ='a'+(y<26?y:25), la = max(la, fin[i]), i++;
        i--, y++;
    }
    if(y<k) cout<<"NO"<<endl;
    else cout<<"YES\n"<<ans<<endl;
}