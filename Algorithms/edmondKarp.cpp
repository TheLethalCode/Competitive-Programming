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

// s = source, t = sink
int cap[103][103], par[103], s, t;
vector < int > to[103];

int bfs() {
    queue < pair < int, int > > Q;
    Q.emplace(0, MAXC);
    par[s] = 0;
    while (!Q.empty()) {
        int u = Q.front().fi, fl = Q.front().se;
        Q.pop();
        FORR (v, to[u]) {
            if (cap[u][v] && par[v] == -1) {
                fl = min(fl, cap[u][v]);
                Q.emplace(v, fl);
                par[v] = u;
                if (v == t) {
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