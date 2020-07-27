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

#define mapipa map< int, vpa >
#define mapii map< int, int >

void dfs(int u, mapipa &mp, mapii &vis, int cnt, pa &mark, int par){
    vis[u]=cnt;
    for(auto v : mp[u]){
        if(v.fi == par) continue;
        if(vis[v.fi]) {
            mark = v;
            continue; 
        };
        dfs(v.fi, mp, vis, cnt, mark, u);
    }
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        mapipa mp; mapii vis;
        FOR(i, n){
            int a, b;
            cin>>a>>b;
            mp[a].pb({b, i+1}), mp[b].pb({a, i+1});
            vis[a]=vis[b]=0;
        }
        pa mark[n+1];int cnt=1;
        for(auto el : vis){
            if(el.se) continue;
            dfs(el.fi, mp, vis, cnt, mark[cnt], -1), cnt++;
        }
        vi ans[cnt];
        for(auto el : vis) ans[el.se].pb(el.fi);
        int des = ans[cnt-1][0];
        cout<<cnt-2<<endl;
        FOR(i, cnt-2){
            int fl=-1, in;
            for(int el : ans[i+1]) if(mp[el].size()==1) fl=el, in=mp[el][0].se;
            if(fl==-1) fl = mark[i+1].fi, in = mark[i+1].se;
            cout<<in<<" "<<fl<<" "<<des<<endl;
        }
    }
    
}