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
#define MAXC 200005

vi ed[MAXC];
vli st[MAXC];
lli ar[MAXC], ans=0;
int n;

pal dfs(int u, int p){
    lli temp = 0, cnt=1;
    FORR(x, ed[u]){
        if(x==p) {
            st[u].pb(0);
            continue;
        }
        pal q = dfs(x, u);
        temp+=q.fi, cnt+=q.se;
        st[u].pb(q.fi);    
    }
    ar[u] = cnt;
    return {temp+cnt, cnt};
}

void dfs1(int u, int p, lli up){
    FORR(x, st[u]) up+=x;
    ans = max(ans, up+n);
    FOR(i, sz(ed[u])){
        int v = ed[u][i];
        if(v==p) continue;
        dfs1(v, u, up-st[u][i]+n-ar[v]);
    }    
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    FOR(i, n-1){
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a);
    }
    dfs(1, -1); dfs1(1, -1, 0);
    cout<<ans<<endl;
}