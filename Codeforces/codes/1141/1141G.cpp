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

int n,k;
vector< vpa > has;
vi nod,ans;

bool comp( int l,  int r) 
{
    return has[l].size() > has[r].size();
}

void dfs(int u, int p, int c)
{
    if(!nod[u])
    {
        int com=1;
        for(auto te:has[u])
        {
            if(com==c)
                com++;
            if(te.fi==p)
                continue;
            ans[te.se] = com;
            dfs(te.fi,u,com);
            com++;
        }
    }
    else
    {
        for(auto te:has[u])
        {
            if(te.fi == p)
                continue;
            ans[te.se]=1;
            dfs(te.fi,u,1);
        }
    }
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>k;
    
    has.resize(n);
    nod.resize(n,0);
    ans.resize(n-1,0);

    vpa v(n-1);
    FOR(i,n-1)
    {
        cin>>v[i].fi>>v[i].se;
        has[v[i].fi-1].pb({v[i].se-1,i});
        has[v[i].se-1].pb({v[i].fi-1,i});
    }

    vi dn;
    FOR(i,n)
        dn.push_back(i);
    sort(all(dn),comp);
    
    // debugA(dn);

    FOR(i,k)
        nod[dn[i]]=1;

    cout<<has[dn[k]].size();nl;
    dfs(dn[k],-1,-1);
    FOR(i,n-1)
        cout<<ans[i]<<" ";
    nl;
}