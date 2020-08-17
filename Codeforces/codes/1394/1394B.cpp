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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %
int n, m, k, ans = 0, deg[MAXC], ok[10][10][10][10];
vector< pair< int, int > > to[MAXC], rto[MAXC];

void solve(int cur, vector< int > &A){
    if(cur == k){
        FOR(i, k){
            FOR(j, k){
                if(ok[i+1][A[i]][j+1][A[j]]){
                    return;
                }
            }
        }
        ans++;
    }
    else{
        for(int i=1;i<=cur+1;i++){
            A.pb(i);
            solve(cur+1, A);
            A.pop_back();
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    FOR(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        to[a].pb(c, b);
        rto[b].pb(c, a);
    }
    FOR(i, n+1){
        sort(to[i].begin(), to[i].end());
        deg[i] = to[i].size();
    }
    int which[n+1][k+1][k+1];
    memset(which, 0, sizeof(which));
    memset(ok, 0, sizeof(ok));
    FOR(i, n+1){
        vector< pair < int, int > > temp;
        FORR(v, rto[i]){
            int pos = lower_bound(to[v.se].begin(), to[v.se].end(), make_pair(v.fi, i)) - to[v.se].begin();
            which[i][deg[v.se]][pos+1]++;
            if(which[i][deg[v.se]][pos+1] == 2){
                ok[deg[v.se]][pos+1][deg[v.se]][pos+1] = 1;
            }
            if(which[i][deg[v.se]][pos+1] == 1){
                temp.pb(deg[v.se], pos+1);
            }
        }
        for(int i=0;i<temp.size();i++){
            for(int j=i+1;j<temp.size();j++){
                pair< int, int > u = temp[i], v = temp[j];
                ok[u.fi][u.se][v.fi][v.se] = 1;
                swap(u, v);
                ok[u.fi][u.se][v.fi][v.se] = 1;
            }
        }
    }
    vector< int > dummy;
    solve(0, dummy);
    cout << ans << '\n';
}