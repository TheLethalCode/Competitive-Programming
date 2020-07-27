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
void dfs(int u, vi &vis, int &d, vi ed[]){
    for(int v : ed[u]){
        if(vis[v]!=-1) continue;
        vis[v] = u;
        if(v==1 || u==1) d--;
        dfs(v, vis, d, ed);
    }
}

int main(int argc, char **argv)
{
    crap;
    int n, m, d;
    cin>>n>>m>>d;
    vi ed[n+1], take;
    FOR(i, m){
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a);
    }
    if(ed[1].size() < d){
        cout<<"NO"<<endl;
        return 0;
    }
    
    vi vis(n+1, -1);
    vis[1]=0;dfs(1, vis, d, ed);
    if(d<0){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int el : ed[1]){
        if(d && vis[el]!=1)
            vis[el]=1, d--;
    }
    cout<<"YES"<<endl;
    FOR(i, n-1)
        cout<<vis[i+2]<<" "<<i+2<<endl;

}