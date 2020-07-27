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
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %
#define MAXC 100005

struct edge{
    int e, a, b, in;
};

int par[MAXC], siz[MAXC], h[MAXC], tin[MAXC], tout[MAXC], n, m, l, t=0;
vi bin[MAXC];
vpa ed[MAXC];

bool is_anc(int x, int a){
    if(tin[x] <= tin[a] && tout[x]>=tout[a]) return true;
    return false;
}

void dfs(int u, int p, int hi){
    tin[u]=t++;
    h[u] = hi;
    bin[u][0] = p;
    FOR(i, l) bin[u][i+1] = bin[bin[u][i]][i];
    FORR(x, ed[u]) dfs(x.fi, u, hi+1);
    tout[u]=t++;
}

int get(int u, int v){
    auto it = lower_bound(all(ed[u]), make_pair(v, -1));
    return it->se;
}

int edgeIndex(int u, int v){
    if(h[v] < h[u]) swap(u, v);
    for(int i=l;i>=0;i--){
        if(!is_anc(bin[v][i], u))
            v=bin[v][i];
    }
    if(is_anc(u, v)) return get(u, v);
    for(int i=l;i>=0;i--){
        if(!is_anc(bin[u][i], v))
            u=bin[u][i];
    }
    int anc = bin[u][0];
    return max(get(anc, u), get(anc, v));
}

int find_p(int x){
    if(x==par[x]) return x;
    return par[x]=find_p(par[x]);
}

void union_r(int a, int b, int c){
    a = find_p(a), b = find_p(b);
    if(siz[a] < siz[b]) swap(a, b);
    ed[a].pb({b, c}), par[b]=par[a];
    siz[a]+=siz[b];
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    vector< edge > E(m);
    vi mark(m, 0);
    l = ceil(log2(n));
    FOR(i, n) par[i+1]=i+1, siz[i+1]=1, bin[i+1].resize(l+1);
    FOR(i, m){
        cin>>E[i].a>>E[i].b>>E[i].e;
        E[i].in = i;
    }
    sort(all(E), [](edge l, edge r){ return l.e<r.e;});
    FOR(i, m){
        int x = E[i].a, y = E[i].b;
        if(find_p(x) == find_p(y)) continue;
        union_r(x, y, i);
        mark[E[i].in]=-1;
    }
    FOR(i, n) sort(all(ed[i+1]));
    dfs(find_p(1), find_p(1), 0);
    FOR(i, m){
        if(mark[E[i].in]) continue;
        int x = edgeIndex(E[i].a, E[i].b);
        mark[E[i].in] = E[x].e;
    }
    FOR(i, m) if(mark[i]!=-1) cout<<mark[i]<<"\n";
}