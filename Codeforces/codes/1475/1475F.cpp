#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define C1 200005
#define C2 2005

int n, par[C2];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int fp(int x) {
    return x == par[x]? x: par[x] = fp(par[x]);
}

bool dfs(vector< int > edge[], vector< int >& col, int u, int p = -1, int c = 0) {
    col[u] = c;
    bool res = true;
    for (int v: edge[u]) {
        if (v != p) {
            if (col[v] == c) {
                return false;
            } else if (col[v] == -1) {
                res &= dfs(edge, col, v, u, c^1);
            }
        }
    }
    return res;
}

bool checkBipartite(vector< int > edge[]) {
    vector< int > col(2*n, -1);
    bool ans = true;
    for (int i = 0; i < 2*n; i++) {
        if (col[i] == -1) {
            ans &= dfs(edge, col, i);
        }
    }
    return ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1000;
    cin >> t;
    while (t--) {
        cin >> n;
        iota(par, par + 2*n, 0);
        vector< string > A(n), B(n);
        vector< pair< int, int > > change[2];
        for (auto &s: A) {
            cin >> s;
        }
        for (auto &s: B) {
            cin >> s;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                change[A[i][j] ^ B[i][j]].emplace_back(i, j);
            }
        }
        for (auto el: change[0]) {
            if (fp(el.fi) != fp(n + el.se)) {
                par[fp(el.fi)] = fp(n + el.se);
            }
        }
        bool ok = true;
        vector< int > edge[2*n];
        for (auto el: change[1]) {
            if (fp(el.fi) == fp(n + el.se)) {
                ok = false;
                break;
            }
            edge[fp(el.fi)].push_back(fp(el.se + n));
            edge[fp(el.se + n)].push_back(fp(el.fi));
        }
        cout << (ok && checkBipartite(edge)? "Yes\n": "No\n");
    }
}