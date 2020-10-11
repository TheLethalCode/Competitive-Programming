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

void bfs(int s, int dis[], vector< int > to[]) {
    memset(dis, 0xff, (n+1) * sizeof(int));
    dis[s] = 0;
    queue< int > q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : to[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
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
        int a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        vector < int > to[n+1];
        for (int i = 0; i < n -1; i++) {
            int x, y;
            cin >> x >> y;
            to[x].pb(y);
            to[y].pb(x);
        }
        int dis[n+1], dis1[n+1], dia = 0, ok = 0;
        pair< int, int > ma;
        bfs(a, dis, to);
        bfs(max_element(dis, dis+n+1) - dis, dis1, to);
        dia = *max_element(dis1, dis1+n+1);
        if (dis[b] <= da || 2*da >= db || dia <= 2*da) {
            ok = 1;
        }
        cout << (ok ? "Alice" : "Bob") << '\n';
    }
}