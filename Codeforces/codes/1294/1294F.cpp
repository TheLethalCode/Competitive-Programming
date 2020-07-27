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
#define mp make_pair

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define EDGE 200005
#define pa3 pair< int, pa >

vi ed[EDGE], depths;
int vis[EDGE];
vpa m1[EDGE];

// %

int dfs(int u){
    vis[u]=1;
    FOR(i, ed[u].size()){
        int v = ed[u][i];
        if(vis[v]) continue;
        m1[u].pb({dfs(v), i});
    }
    sort(m1[u].rbegin(), m1[u].rend());
    return m1[u].empty()?1:m1[u][0].fi+1;
}

int ans=0, node;
void dfs1(int u, int up=0){
    vis[u]=1;
    if(m1[u].size() == 2 && m1[u][0].fi + m1[u][1].fi + up > ans)
        ans = m1[u][0].fi + m1[u][1].fi + up, node = u;
    if(m1[u].size() > 2){
        int tem = m1[u][0].fi + m1[u][1].fi + max(up, m1[u][2].fi);
        if(tem > ans)
            ans = tem, node = u;
    }
    FOR(i, ed[u].size()){
        int v = ed[u][i];
        if(vis[v]) continue;
        int edg = (i==m1[u][0].se)?(m1[u].size()==1?0:m1[u][1].fi):m1[u][0].fi;
        dfs1(v, max(up, edg)+1);
    }
}

int x, y, z;
pa dfs2(int u=node){
    vis[u]=1;
    vpa dep;
    for(int v : ed[u]){
        if(vis[v]) continue;
        dep.pb(dfs2(v));
    }
    if(dep.empty()) return {1, u};
    if(u==node){
        sort(dep.rbegin(), dep.rend());
        x = dep[0].se, y = dep[1].se, z=dep[2].se;
    }
    pa te = *max_element(all(dep));
    return {te.fi+1, te.se};
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    FOR(i, n-1){
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a);
    }
    vi tw;
    FOR(i, n) if(ed[i+1].size()==1) tw.pb(i+1);
    if(tw.size()==2){
        cout<<n-1<<endl;
        if(tw[0]!=1 && tw[1]!=1) cout<<1<<" "<<tw[0]<<" "<<tw[1];
        else if(tw[0]!=2 && tw[1]!=2) cout<<2<<" "<<tw[0]<<" "<<tw[1];
        else cout<<3<<" "<<tw[0]<<" "<<tw[1];
        cout<<endl;
        return 0;
    }
    FOR(i, n) vis[i+1]=0;
    dfs(1);
    FOR(i, n) vis[i+1]=0;
    dfs1(1);
    FOR(i, n) vis[i+1]=0;
    dfs2();
    cout<<ans<<endl;
    cout<<x<<" "<<y<<" "<<z<<endl;
}