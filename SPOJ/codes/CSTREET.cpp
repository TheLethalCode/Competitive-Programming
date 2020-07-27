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

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

vi par;
vector< vi > po;
int n;


int find(int x)
{
    if(x==par[x])
        return x;
    return par[x] = find(par[x]);
}

void uni(int i,int j)
{
    int a = find(i), b = find(j);
    if(po[a].size() > po[b].size())
        swap(po[a],po[b]);
    for(int q:po[a])
        po[b].pb(q);
    par[a]=b;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,m;
        cin>>p>>n>>m;

        par.clear();
        po.clear();
        par.resize(n);
        po.resize(n);
        FOR(i,n)
            par[i]=i,po[i].pb(i);
        
        vector< pair< int, pa > > v(m);
        FOR(i,m)
            cin>>v[i].se.fi>>v[i].se.se>>v[i].fi;
        sort(all(v));

        lli ans=0;
        for(auto r:v)
        {
            if(find(r.se.fi-1) == find(r.se.se-1))
                continue;
            ans+=r.fi;
            uni(r.se.fi-1,r.se.se-1);
        }
        cout<<ans*p;nl;
    }
}