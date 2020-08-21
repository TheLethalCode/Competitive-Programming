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

int n;
lli S[MAXC];
vector< int > to[MAXC];
vector< lli > A;

void dfs(int u, int p = 0) {
    S[u] = 1;
    FORR (v, to[u]) {
        if (v != p) {
            dfs(v, u);
            S[u] += S[v];
            A.pb(1LL * S[v] * (n-S[v]));
        }
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
        A.clear();
        FOR (i, n+1) {
            S[i] = 0;
            to[i+1].clear();
        }
        FOR (i, n-1) {
            int a, b;
            cin >> a >> b;
            to[a].pb(b);
            to[b].pb(a);
        }
        dfs(1);
        int m;
        cin >> m;
        vector< lli > V(m);
        FOR (i, m) {
            cin >> V[i];
        } 
        sort(A.rbegin(), A.rend());
        sort(V.rbegin(), V.rend());
        lli ans = 0;
        if (m <= n-1) {
            for (int i = 0; i < m; i++) {
                ans = (ans + A[i] * V[i]) % mod;
            }
            for (int i = m; i < n-1; i++) {
                ans = (ans + A[i]) % mod;
            }
        } else {
            for (int i = 0; i < m - n + 1; i++) {
                V[i+1] *= V[i];
                V[i+1] %= mod; 
            }
            for (int i = m - n + 1; i < m; i++) {
                ans = (ans + (A[i - m + n - 1] % mod) * V[i]) % mod;
            }
        }
        cout << ans << '\n';
    }
}