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

vi ed[100005];
lli v[100005];
int vis[100005];
lli ans = 0;

void dfs(int u, map< lli, lli > &mp){
    vis[u]=1;
    map< lli, lli > st;
    st[v[u]]=1, ans += v[u];
    for(auto el : mp){
        lli gc = __gcd(el.fi, v[u]);
        if(st.count(gc)) st[gc]+=el.se;
        else st[gc]=el.se;
        ans = (ans + gc*el.se) % mod;
    }
    for(int el : ed[u]){
        if(vis[el]) continue;
        dfs(el, st);
    }
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    FOR(i, n) cin>>v[i+1], vis[i+1]=0;
    FOR(i, n-1){
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a);
    }
    map<lli, lli > mp;
    dfs(1, mp);
    cout<<ans<<endl;
}