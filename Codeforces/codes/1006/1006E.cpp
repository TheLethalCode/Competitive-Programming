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
vector< int > to[MAXC], fin;
int t = 0, tout[MAXC], tin[MAXC], rel[MAXC];

void dfs(int u, int p = 0) {
    fin.pb(u);
    tin[u] = t++;
    FORR (v, to[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = t++;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    FOR (i, n - 1) {
        int a;
        cin >> a;
        to[a].pb(i+2);
        to[i+2].pb(a);
    }
    FOR (i, n) {
        sort(to[i+1].begin(), to[i+1].end());
    }
    dfs(1);
    FOR (i, n) {
        rel[fin[i]] = i;
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        int off = rel[x] + y - 1;
        if (off >= n || !(tin[x] <= tin[fin[off]] && tout[fin[off]] <= tout[x])) {
            cout << "-1\n";
        } else {
            cout << fin[off] << '\n';
        }
    } 
}