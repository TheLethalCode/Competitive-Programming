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

vpa ed[5001];
int n, m, vis[5001], ans[5001], fl=0;

void dfs(int u){
    vis[u]=1;
    FORR(v, ed[u]){
        ans[v.se]=1;
        if(vis[v.fi]==1) fl=1, ans[v.se]=2;
        else if(vis[v.fi]==-1) dfs(v.fi);
    }
    vis[u]=0;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    FOR(i, n) vis[i+1]=-1;
    FOR(i, m){
        ans[i]=-1;
        int a, b;
        cin>>a>>b;
        ed[a].pb({b, i});
    }
    FOR(i, n) if(vis[i+1]==-1) dfs(i+1);
    cout<<*max_element(ans, ans+m)<<endl;
    FOR(i, m) cout<<ans[i]<<" ";
    cout<<endl;
}