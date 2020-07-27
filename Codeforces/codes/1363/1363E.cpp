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

multiset<int> up;
vector< vi > ed, cnt;
vi co;
vpa di;

void dfs(int u, vi &vis){
    vis[u] = 1;
    up.insert(co[u]);
    for(int v : ed[u]){
        if(vis[v]!=-1) continue;
        dfs(v, vis);
        FOR(i, 5) cnt[u][i] += cnt[v][i];
    }
    cnt[u][di[u].fi]++, cnt[u][di[u].se+2]++;
    cnt[u][4] += (di[u].fi != di[u].se);
    up.erase(up.find(co[u]));
    if(!up.empty()) {
        co[u]=min(co[u], *up.begin());
    }
}

int solve(int u, vi &vis, lli &ans){
    vis[u]=1;
    int temp = 0;
    for(int v : ed[u]){
        if(vis[v]!=-1) continue;
        temp += solve(v, vis, ans);
    }
    int ch = cnt[u][4]-temp-abs(cnt[u][0]-cnt[u][2]);
    ans += 1LL*ch*co[u];
    return ch+temp; 
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    co.resize(n+1), ed.resize(n+1), di.resize(n+1), cnt.resize(n+1, vi(5,0));
    FOR(i, n) cin>>co[i+1]>>di[i+1].fi>>di[i+1].se;
    FOR(i, n-1){
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a);
    }
    vi vis(n+1, -1);
    dfs(1, vis);
    if(cnt[1][0] != cnt[1][2]){
        cout<<-1<<endl;
        return 0;
    }
    FOR(i, n) vis[i+1]=-1;
    lli ans = 0;solve(1, vis, ans);
    cout<<ans<<endl;
}