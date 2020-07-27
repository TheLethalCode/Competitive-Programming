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
int k;

int dfs(int u, vi &vis, vpa ed[], lli &G, lli &B){
    vis[u]=1;
    int cnt=1;
    for(pa v : ed[u]){
        if(vis[v.fi]!=-1) continue;
        int te = dfs(v.fi, vis, ed, G, B);
        cnt+=te, B+=1LL*min(te, 2*k-te)*v.se, G+=(te&1)?v.se:0;
    }
    return cnt;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        cin>>k;
        lli G=0, B=0; vpa ed[2*k+1];
        FOR(i, 2*k-1) {
            int a, b, c;
            cin>>a>>b>>c;
            ed[a].pb({b, c}), ed[b].pb({a, c});
        }
        vi vis(2*k+1, -1);
        dfs(1, vis, ed, G, B);
        cout<<G<<" "<<B<<endl;
    }
}