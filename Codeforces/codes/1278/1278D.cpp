#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
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
vi ed[5*100000+6];

void dfs(int u, vi &vis){
    vis[u-1]=1;
    for(int v : ed[u]) if(vis[v-1]==-1) dfs(v, vis);
}

int main(int argc, char **argv)
{
    crap;
    int n, edges=0;
    cin>>n;
    vpa v(n);
    FOR(i, n) cin>>v[i].fi>>v[i].se;
    
    sort(all(v));
    vector< pair< pa, int > > events;
    FOR(i, n) events.pb({{v[i].fi, 0}, i+1}), events.pb({{v[i].se, 1}, i+1});
    sort(all(events));

    set< int, greater<int> > s;
    for(auto el : events){
        if(!el.fi.se) s.insert(el.se);
        else{
            s.erase(el.se);
            for(int i : s){
                if(i < el.se) break;
                ed[el.se].pb(i), ed[i].pb(el.se);
                edges++;
                if(edges >= n){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        } 
    }
    vi vis(n, -1);
    dfs(1, vis);
    if(*min_element(all(vis))==-1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}