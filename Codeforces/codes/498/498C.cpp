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
int cap[103][103], par[103], n;
vector < int > to[103];

int bfs() {
    queue < pair < int, int > > Q;
    Q.emplace(0, MAXC);
    par[0] = 0;
    while (!Q.empty()) {
        int u = Q.front().fi, fl = Q.front().se;
        Q.pop();
        FORR (v, to[u]) {
            if (cap[u][v] && par[v] == -1) {
                fl = min(fl, cap[u][v]);
                Q.emplace(v, fl);
                par[v] = u;
                if (v == n + 1) {
                    return fl;
                }
            }
        }
    }
    return 0;
}

int maxFlow() {
    int tot = 0, cur_flow;
    memset(par, 0xff, sizeof(par));
    while (cur_flow = bfs()) {
        tot += cur_flow;
        int cur = n + 1;
        while (cur) {
            cap[par[cur]][cur] -= cur_flow;
            cap[cur][par[cur]] += cur_flow;
            cur = par[cur];
        }
        memset(par, 0xff, sizeof(par));
    }
    return tot;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    map < int, int > A[n];
    set < int > S;
    FOR (i, n) {
        int x;
        cin >> x;
        for (int j = 2; j <= sqrt(x); j++) {
            if (x % j == 0) {
                S.insert(j);
                int cnt = 0;
                while (x % j == 0) {
                    x /= j;
                    cnt++;
                }
                A[i][j] = cnt;
            }
        }
        if (x != 1) {
            A[i][x] = 1; 
            S.insert(x);
        }
    }

    vector < pair < int, int > > E(m);
    FOR (i, m) {
        cin >> E[i].fi >> E[i].se;
        to[E[i].fi].pb(E[i].se);
        to[E[i].se].pb(E[i].fi);
    }
    for (int i = 2; i <= n; i+=2) {
        to[0].pb(i);
        to[i].pb(0);
    }
    for (int i = 1; i <= n; i+=2) {
        to[n+1].pb(i);
        to[i].pb(n+1);
    }

    int ans = 0;
    FORR (p, S) {
        memset(cap, 0, sizeof(cap));
        FORR (e, E) {
            int x = e.fi, y = e.se;
            if (x % 2) {
                swap(x, y);
            }
            cap[x][y] = MAXC;
        }
        for (int i = 2; i <= n; i+=2) {
            cap[0][i] = A[i-1][p];
        }
        for (int i = 1; i <= n; i+=2) {
            cap[i][n+1] = A[i-1][p];
        }
        ans += maxFlow();
    }
    cout << ans << "\n";
}