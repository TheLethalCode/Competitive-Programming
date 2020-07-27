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
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %

void dfs(int u, vector< vi > &ed, vi &vis, vpa &ti, vi &dis, int &t)
{
    if(!vis[u])
        vis[u]=-1;
    t++, ti[u].fi=t;
    for(int v : ed[u])
        if(!vis[v])
            vis[v]=u, dis[v] = dis[u]+1, dfs(v, ed, vis, ti, dis, t);
    t++, ti[u].se = t;
}

int main(int argc, char **argv)
{
    crap;
    int n, m, t=0;
    cin>>n>>m;
    vector< vi > v(n+1);
    FOR(i, n-1)
    {
        int a, b;
        cin>>a>>b;
        v[a].pb(b), v[b].pb(a);
    }
    vpa ti(n+1);
    vi vis(n+1,0), dis(n+1, 0);
    dfs(1, v, vis, ti, dis, t);
    while(m--)
    {
        int k;
        cin>>k;
        vi te(k);
        int in, va = 0;
        FOR(i, k)
        {
            cin>>te[i];
            if(dis[te[i]] > va)
                in = i, va = dis[te[i]];
        }
        if(k==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        int fl = 0;
        FOR(i, k)
        {
            if(te[i]!=1 & i!=in)
            {
                te[i]=vis[te[i]];
                if(ti[te[i]].fi <= ti[te[in]].fi & ti[te[i]].se >= ti[te[in]].se)
                    continue;
                fl=1;
                break;
            }
        }
        if(fl)
            cout<<"NO";
        else
            cout<<"YES";
        cout<<endl;
        
    }
}