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
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %
#define xors ^

#define pta pair< lli, pa >

vi par;
vli val;
vi siz;
vi loc;

int find_p(int x){
    if(x == par[x])
        return x;
    return par[x] = find_p(par[x]);
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vpa v(n);
    vli c(n), k(n);
    lli ans = 0;
    par.resize(n), val.resize(n), siz.resize(n), loc.resize(n);
    FOR(i, n) cin>>v[i].fi>>v[i].se, par[i]=i, siz[i]=1, loc[i]=i;
    FOR(i, n) cin>>c[i], val[i] = c[i], ans += c[i];
    FOR(i, n) cin>>k[i];

    set< pta > st;
    FOR(i, n){
        FOR(j, i){
            lli co = abs(v[i].fi - v[j].fi) + abs(v[i].se - v[j].se);
            co *= k[i] + k[j];
            st.insert({co, {j, i}});
        }
    }

    vi po(n, 1);
    vector< vi > ma(n, vi(n, 0));
    for(auto ed:st){
        
        int i = ed.se.fi, j = ed.se.se;
        int pi = find_p(i), pj=find_p(j);
        if(pi == pj || (val[pi] <= ed.fi && val[pj] <= ed.fi)) 
            continue;

        ma[i][j]=ma[j][i]=1;
        if(siz[pi] < siz[pj])
            swap(pi, pj);

        ans += ed.fi - max(val[pi], val[pj]);
        par[pj] = pi, val[pi] = min(val[pi], val[pj]), siz[pi] += siz[pj];
        
        int temp = (val[loc[pi]] < val[loc[pj]])?loc[pj]:loc[pi]; 
        loc[pi] = (val[loc[pi]] < val[loc[pj]])?loc[pi]:loc[pj];
        po[temp] = 0;
    }
    
    vi ans1;
    vpa ans2;
    FOR(i, n) if(po[i]) ans1.pb(i);
    FOR(j, n) FOR(i, j) if(ma[i][j]) ans2.pb({i+1, j+1});
    cout<<ans<<endl;
    cout<<ans1.size()<<endl;
    for(auto te : ans1) cout<<te+1<<" ";cout<<endl;
    cout<<ans2.size()<<endl;
    for(auto te : ans2) cout<<te.fi<<" "<<te.se<<endl;
    
}