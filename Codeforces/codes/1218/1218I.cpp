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

int n, v[2002][2002], ar[2002], par[4004], vis[4004], ans[4004], cnt=0;
vi ed[4004], col[4004];
set< int > ed2[4004];

int find_p(int x){
    if(par[x]==x) return x;
    return par[x]=find_p(par[x]);
}

void union_r(int a, int b){
    a = find_p(a), b = find_p(b);
    if(a!=b) par[a] = b;
}

void dfs(int u, int c){
    vis[u]=c, col[c].pb(u);
    FORR(v, ed[u]) if(vis[v] == -2) dfs(v, c^1);
}

void done(){
    cout<<-1<<endl;
    exit(0);
}

void dfs1(int u, int c){
    ans[u] = c;
    FORR(v, ed2[u]) {
        if(ans[v] != c^1) done();
        if(ans[v] == -1) dfs1(v, c^1);
    }
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    FOR(i, 2*n+1) vis[i]=ans[i]=-1, par[i]=i;
    
    FOR(i, n) FOR(j, n) {
        char x;
        cin>>x;
        v[i][j]=x-'0';
    }
    FOR(i, n) FOR(j, n) {
        char x;
        cin>>x;
        v[i][j] = (v[i][j]!=x-'0');
    }
    FOR(i, n) {
        char x;
        cin>>x;
        ar[i]=x-'0';
    }

    FOR(i, n) FOR(j, n) {
        if(v[i][j]) {
            if(!(ar[i] || ar[j])) done();
            if(ar[i] && ar[j]) {
                ed[i].pb(n+j), ed[n+j].pb(i);
                vis[i]=vis[n+j]=-2;
            }
        }
        if(!v[i][j] && ar[i] && ar[j]) union_r(i, n+j);
    }
    FOR(i, 2*n+1) if(vis[i]==-2) dfs(i, cnt), cnt+=2;
    FOR(i, cnt) {
        int p = col[i][0];
        FORR(x, col[i]) union_r(p, x);
    }

    FOR(i, n) FOR(j, n){
        if(!ar[i] && ar[j]){
            if(ans[find_p(i)] == !v[i][j]) done();
            ans[find_p(i)]=v[i][j];
        }
        if(ar[i] && !ar[j]){
            if(ans[find_p(n+j)] == !v[i][j]) done();
            ans[find_p(n+j)]=v[i][j];
        }
    }
    FOR(i, cnt/2) {
        int a = col[2*i][0], b = col[2*i+1][0];
        a = find_p(a), b = find_p(b);
        if(ans[a] == ans[b] && ans[a]!=-1) done();
        if(ans[a] == -1 && ans[b]!=-1) ans[a] = !ans[b];
        if(ans[a] != -1 && ans[b]==-1) ans[b] = !ans[a];
    }
    FOR(i, cnt/2) {
        int a = col[2*i][0], b = col[2*i+1][0];
        a = find_p(a), b = find_p(b);
        if(ans[a] ==-1 && ans[b]==-1) ed2[a].insert(b), ed2[b].insert(a);
    }
    FOR(i, 2*n+1) if(!ed2[i].empty() && ans[i]==-1) dfs1(i, 0);
    
    int temp = 0;
    FOR(i, 2*n+1) if(ans[find_p(i)]==1) temp++;
    cout<<temp<<endl;
    FOR(i, 2*n+1) if(ans[find_p(i)]==1){
        if(i<n) cout<<"row "<<i<<endl;
        else cout<<"col "<<i-n<<endl;
    } 

}