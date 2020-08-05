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
vector< pair< int, int > > to[MAXC];
int times[MAXC], E[MAXC], T[MAXC];

int dfs(int u, int p = 0){
    int mark = 0;
    FORR(v, to[u]){
        if(v.fi != p){
            int temp = dfs(v.fi, u);
            times[v.se] = temp;
            mark += temp;
        }
    }
    return mark?mark:1;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        lli S, cur = 0;
        cin >> n >> S;
        FOR(i, n){
            to[i+1].clear();
            times[i] = 0;
        }
        FOR(i, n-1){
            int a, b;
            cin >> a >> b >> E[i] >> T[i];
            to[a].pb(b, i);
            to[b].pb(a, i);
        }
        dfs(1);
        vector< lli > V[2];
        FOR(i, n-1){
            cur += 1LL * times[i] * E[i];
            while(E[i]){
                V[T[i]-1].pb(1LL * times[i] * (E[i] - E[i]/2));
                E[i] >>= 1;
            }
        }
        FOR(i, 2){
            sort(V[i].begin(), V[i].end());
            reverse(V[i].begin(), V[i].end());
        }
        int W1 = 0, W2 = 0;
        while(W1 < V[0].size() && cur > S){
            cur -= V[0][W1++];
            ans++;
        }
        while(cur > S){
            cur -= V[1][W2++];
            ans += 2;
        }
        while(W1 > 0 && cur <= S){
            cur += V[0][--W1];
            while(cur > S && W2 < V[1].size()){
                cur -= V[1][W2++];
            }
            if(cur <= S){
                ans = min(ans, W1 + 2*W2);
            }
        }
        cout << ans << '\n';
    }   
}