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
vector<  vi > v,comp;
vi temp;
vi vis;

lli modpw(lli n,lli p)
{
    if(!p)
        return 1;
    if(p&1)
        return (modpw(n,p-1)*n)%mod;
    lli t=modpw(n,p>>1);
    return (t*t)%mod;
}

void dfs(int u,int p)
{
    vis[u]=1;
    temp.pb(u);
    for(int t:v[u])
    {
        if(t==p || vis[t])
            continue;
        dfs(t,u);
    }
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>k;
    v.resize(n),
    vis.resize(n,0);
    FOR(i,n-1)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c==0)
            v[a-1].pb(b-1), v[b-1].pb(a-1);
    }
    FOR(i,n)
    {
        if(!vis[i])
        {
            temp.clear();
            dfs(i,-1);
            comp.pb(temp);
        }
    }
    lli ans=modpw(n,k);
    for(auto l:comp)
        ans-=modpw(l.size(),k),ans=(ans+mod)%mod;
    
    cout<<ans;nl;
}