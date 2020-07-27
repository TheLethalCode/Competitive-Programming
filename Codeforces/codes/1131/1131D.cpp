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

// %
vi ed[2005], par, siz, ans, rec, vis, topo;
int n, m, fl=0;

int find_p(int x){
    if(x == par[x])
        return x;
    return par[x] = find_p(par[x]);
}

void union_te(int i, int j){
    int pi = find_p(i), pj=find_p(j);
    if(pi == pj) return;
    if(siz[pi] < siz[pj])
        swap(pi, pj);
    par[pj] = pi, siz[pi] += siz[pj];
}

void pre(){
    par.resize(n+m+1, 0);
    FOR(i, n+m) par[i]=i;
    siz.resize(n+m+1, 1);
    ans.resize(n+m+1, 0), rec.resize(n+m+1, 0);
    vis.resize(n+m+1, 0);
}

int dfs(int u){
    vis[u]=1, rec[u]=1;
    int chi=0;
    for(int v : ed[u]){
        if(vis[v] && rec[v]) fl=1;
        else if(vis[v]) chi=min(chi, ans[v]-1);
        else chi=min(chi, dfs(v)-1);
    }
    rec[u]=0;
    return ans[u] = chi;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    vector< string > v(n);
    pre();
    FOR(i, n) cin>>v[i];
    FOR(i, n) FOR(j, m) if(v[i][j]=='=') union_te(i, j+n);
    FOR(i, n) FOR(j, m){
        int x = find_p(i), y=find_p(n+j);
        if(x==y && v[i][j]!='=') fl=1;
        if(x!=y){
            if(v[i][j]=='<') ed[x].pb(y);
            else ed[y].pb(x);
        }
    }
    FOR(i, n+m) if(!vis[find_p(i)]) dfs(find_p(i));
    if(fl) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int sm = *min_element(all(ans));
    FOR(i, n) cout<<ans[find_p(i)]-sm+1<<" ";
    cout<<endl;
    FOR(i, m) cout<<ans[find_p(i+n)]-sm+1<<" ";
    cout<<endl;
}