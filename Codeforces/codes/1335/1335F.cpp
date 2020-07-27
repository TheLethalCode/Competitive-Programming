#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
template <class T> inline bool chmin(T a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

#define MAXC 1000001

int n, m, v[MAXC], c[MAXC], vis[MAXC], des[MAXC];
vector< pair< int, int > > cyc(MAXC, {-1, -1});
vector< int > ar[MAXC];

pair<int, int> dfs(int u, int dep, int &F){
    vis[u] = dep;
    if(vis[v[u]]==-1){
        cyc[u] = dfs(v[u], dep+1, F);
        des[u] = F;
    }
    else if(cyc[v[u]].fi==-1){
        F = des[u] = u;
        cyc[u] = {0, dep-vis[v[u]]+1};
        ar[u].resize(cyc[u].se);
    }
    else{
        F = des[u] = des[v[u]];
        cyc[u] = cyc[v[u]];
        cyc[u].fi++;
    }
    ar[des[u]][cyc[u].fi%cyc[u].se] += (c[u]==0);
    return {cyc[u].fi+1, cyc[u].se};
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        FOR(i, n){
            FOR(j, m){
                char x;
                cin>>x;
                c[i*m+j] = x-'0';
                ar[i*m+j].clear();
                cyc[i*m+j] = {-1, -1};
                vis[i*m+j] = -1;
            }
        }
        FOR(i, n){
            FOR(j, m){
                char x;
                cin>>x;
                if(x=='R') {
                    v[i*m+j] = i*m+j+1;
                }
                else if(x=='L'){
                    v[i*m+j] = i*m+j-1;
                }
                else if(x=='U'){
                    v[i*m+j] = (i-1)*m+j;
                }
                else{
                    v[i*m+j] = (i+1)*m+j;
                }
            }
        }
        FOR(i, n*m){
            if(vis[i]==-1){
                int f;
                dfs(i, 0, f);
            }
        }
        int ans = 0, bla = 0;
        FOR(i, n*m){
            if(!ar[i].empty()){
                ans += sz(ar[i]);
                FOR(j, sz(ar[i])){
                    bla += (ar[i][j] > 0);
                }
            }
        }
        cout<<ans<<" "<<bla<<endl;
    }
}