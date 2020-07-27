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
int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vli v(n);
    FOR(i, n) cin>>v[i];

    vector< set<int> > ed(n), ed1;
    FOR(i, 63){
        int cnt = 0;
        vi te;
        FOR(j, n){
            if(v[j] & (1LL<<i)){
                te.pb(j), cnt++;
                if(cnt == 3){
                    cout<<3<<endl;
                    return 0;
                }
            }
        }
        if(cnt == 2){
            ed[te[0]].insert(te[1]);
            ed[te[1]].insert(te[0]);
        }
    }
    vi ver;
    FOR(i, n) if(ed[i].size()) ver.pb(i);
    n = ver.size();
    
    int ans = 1e9;
    FOR(i, n){
        vi par(n, -1), vis(n, -1);
        queue<int> q;
        q.push(i), vis[i]=0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int r : ed[ver[u]]){
                int v = lower_bound(all(ver), r) - ver.begin();
                if(v == par[u]) continue;
                if(vis[v] != -1){
                    ans = min(ans, vis[v]+vis[u]+1);
                    continue;
                }
                par[v] = u, vis[v]=vis[u]+1, q.push(v);
            }
        }
    }
    if(ans > n) cout<<-1<<endl;
    else cout<<ans<<endl;
}