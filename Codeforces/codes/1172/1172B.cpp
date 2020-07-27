#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
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
vli fac(2*1e5+1,1);

lli pomo(lli n, lli p){
    if(!p) return 1;
    if(p&1) return (pomo(n, p-1)*n)%mod;
    lli t = pomo(n, p>>1);
    return (t*t)%mod;
}

lli dfs(int u, vector< vi > &ed, vi &vis){
    vis[u]=1;
    lli temp = 1;
    int cnt=0;
    for(int v : ed[u]){
        if(vis[v]!=-1) continue;
        temp *= dfs(v, ed, vis), temp %= mod, cnt++;
    }
    temp *= fac[cnt+1], temp %= mod;
    return temp;
}

int main(int argc, char **argv)
{
    crap;
    FOR(i,2*1e5){
        fac[i+1]=fac[i]*(i+1), fac[i+1]%=mod;
    }

    int n;
    cin>>n;
    vector< vi > ed(n+1);
    FOR(i, n-1){
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a);
    }
    vi vis(n+1, -1);
    lli ans = dfs(1, ed, vis);
    ans *= pomo(ed[1].size()+1, mod-2), ans %= mod;
    ans *= n, ans %= mod;
    cout<<ans<<endl;
}