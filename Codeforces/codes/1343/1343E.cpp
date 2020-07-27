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

vi ed[200005];
// %

void bfs(int s, vi &vis, vi &par){
    queue< int > q;
    q.push(s), vis[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : ed[u]){
            if(vis[v]!=-1) continue;
            par[v]=u, vis[v]=vis[u]+1, q.push(v);
        }
    }
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int n, m, a, b, c;
        cin>>n>>m>>a>>b>>c;
        vli v(m), pref(m+1);
        FOR(i, n) ed[i+1].clear();
        FOR(i, m) cin>>v[i];
        sort(all(v));
        FOR(i, m) pref[i+1]=pref[i]+v[i];
        FOR(i, m){
            int a, b;
            cin>>a>>b;
            ed[a].pb(b), ed[b].pb(a);
        }
        vi da(n+1, -1), db(n+1, -1), dc(n+1, -1);
        vi Pa(n+1, -1), Pb(n+1, -1), Pc(n+1, -1);
        bfs(a, da, Pa), bfs(b, db, Pb), bfs(c, dc, Pc);

        lli ans = 1e18;
        for(int x=1;x<=n;x++){
            int Cx = dc[x], Bx = db[x], Ax=da[x];
            if(Ax+Bx+Cx>m) continue;
            lli D = pref[Bx], E=pref[Cx+Ax+Bx]-pref[Bx];
            ans = min(ans, 2*D+E);
        }
        cout<<ans<<endl;
    }
}