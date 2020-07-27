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

// %
int n, m, a[5001], b[5001], c[5001];
vpa ed[5001];
vi ans, ord;

vi bfs(int a, int b){
    vpa par(n+1, {-1, -2});
    queue< int > q;
    q.push(a), par[a]={0, -1};
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(pa v : ed[u]){
            if(par[v.fi].fi!=-1) continue;
            par[v.fi]={u, v.se}, q.push(v.fi);

            if(v.fi == b){
                vi temp;
                while(v.fi) temp.pb(v.se), v = par[v.fi];
                return temp; 
            }
        }
    }
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    FOR(i, n-1){
        int a, b;
        cin>>a>>b;
        ed[a].pb({b, i}), ed[b].pb({a, i});
    }
    cin>>m;
    FOR(i, m) cin>>a[i]>>b[i]>>c[i];
    ord.resize(m);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){
        return c[i]>c[j];
    });
    ans.assign(n-1, -1);
    FOR(i, m){
        int fl=0;
        for(int e : bfs(a[ord[i]], b[ord[i]])) {
            if(ans[e]==-1 || ans[e]==c[ord[i]]){
                fl=1;
                ans[e]=c[ord[i]];
            } 
        }
        if(!fl){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int el : ans) cout<<(el==-1?1000000:el)<<" ";
    cout<<endl;
}