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
#define MAXC 100005
// %
int n, m, ti, ans, vis[MAXC], T[MAXC], A[MAXC], B[MAXC], C[MAXC];
vector< int > to[MAXC], Y, ord;

bool dfs(int u){
    vis[u] = 2;
    ti++;
    bool ok = 1;
    FORR(v, to[u]){
        if(vis[v]==2){
            return false;
        }
        if(!vis[v]){
            ok &= dfs(v);
        }
    }
    T[u] = ti++;
    vis[u] = 1;
    return ok;
}

int solve(int k){
    int pos = lower_bound(ord.begin(), ord.end(), k+1, [&](int i, int k){
        return C[i] < k;
    }) - ord.begin();
    for(int i=pos; i<m;i++){
        to[A[ord[i]]].pb(B[ord[i]]);
    }
    bool ok = 1;
    FOR(i, n){
        if(!vis[i+1]){
            ok &= dfs(i+1);
        }
    }
    if(ok){
        ans = k;
        Y.clear();
        FORR(i, ord){
            if(T[A[i]] < T[B[i]]){
                Y.pb(i+1);
            }
        }
    }
    ti = 0;
    FOR(i, n){
        vis[i+1] = 0;
        to[i+1].clear();
    }
    return ok;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i, m){
        cin >> A[i] >> B[i] >> C[i];
    }
    ord.resize(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return C[i] < C[j];
    });
    int lo = 0, hi = m-1, mid;
    while(hi >= lo){
        if(solve(C[ord[mid=lo+hi>>1]])){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    solve(0);
    cout << ans << ' ' << Y.size() << '\n';
    FORR(x, Y){
        cout << x << " ";
    }
    cout << '\n';
}