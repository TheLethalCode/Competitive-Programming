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
    int n, k;
    cin>>n>>k;
    vli al, bo, to;
    lli ans = 0;
    FOR(i, n){
        int a, b, c;
        cin>>a>>b>>c;
        if(b && c) to.pb(a);
        else if(b) al.pb(a);
        else if(c) bo.pb(a);
    }
    al.pb(2*mod), bo.pb(2*mod), to.pb(2*mod);
    sort(all(to)), sort(all(al)), sort(all(bo));
    int x = 0, c1 = 0, c2 = 0, c3 = 0;
    while(c1 < sz(al) && c2 < sz(bo) && c3<sz(to)){
        if(x==k) break;
        if(to[c3] <= al[c1] + bo[c2]) ans+=to[c3++];
        else ans+=al[c1++] + bo[c2++];
        x++;
    }
    if(x<k || ans >= 2*mod) cout<<-1<<endl;
    else cout<<ans<<endl;
}