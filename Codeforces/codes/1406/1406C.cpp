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

vector< int > to[MAXC];
int C[MAXC], S[MAXC], leaf, n;

void dfs(int u, int p = 0) {
    S[u] = 1;
    C[u] = 0;
    for (int v : to[u]) {
        if (v != p) {
            dfs(v, u);
            S[u] += S[v];
            C[u] = max(S[v], C[u]);
        }
    }
    C[u] = max(C[u], n - S[u]);
    if (S[u] == 1) {
        leaf = u;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n+1; i++) {
            to[i].clear();
        }
        for (int i = 0, a, b; i < n-1; i++) {
            cin >> a >> b;
            to[a].pb(b);
            to[b].pb(a);
        }
        dfs(1, 0);
        int up = *min_element(C + 1, C + n + 1);
        vector< int > cnt;
        for (int i = 1; i <= n; i++) {
            if (C[i] == up) {
                cnt.pb(i);
            }
        }
        if (cnt.size() == 1) {
            cout << 1 << " " << to[1][0] << '\n';
            cout << 1 << " " << to[1][0] << '\n';
        } else {
            dfs(cnt[0], cnt[1]);
            cout << leaf << " " << to[leaf][0] << '\n';
            cout << leaf << " " << cnt[1] << '\n';
        }
    }
} 