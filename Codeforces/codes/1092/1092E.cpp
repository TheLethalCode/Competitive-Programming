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
#define MAXC 2000
// %

int n;
vector< int > to[MAXC];

void bfs(int s, vector< int > &dis, vector< int > &par) {
    dis.assign(n+1, -1);
    // for (int v : dis) {
    //     cout << v << " ";
    // }
    // cout << "##" << endl;
    dis[s] = 0;
    par[s] = s;
    queue< int > q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : to[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        to[v].pb(u);
        to[u].pb(v);
    }

    vector< int > comp(n+1, -1);
    vector< pair< int, int > > rep;
    for (int i = 1, cnt = 1; i <= n; i++) {
        if (comp[i] == -1) {
            vector< int > dis(n+1, -1), par(n+1);
            
            bfs(i, dis, par);
            pair< int, int > madis;
            for (int j = 1; j <= n; j++) {
                madis = max(madis, make_pair(dis[j], j));
                if (dis[j] != -1) {
                    comp[j] = cnt;   
                }
            }
            
            bfs(madis.se, dis, par);
            madis = {0, 0};
            for (int j = 1; j <= n; j++) {
                madis = max(madis, make_pair(dis[j], j));
            }
            
            vector< int > path;
            int cur = madis.se;
            while (par[cur] != cur) {
                path.pb(cur);
                cur = par[cur];
            }
            path.pb(cur);
            rep.pb(madis.fi, path[(path.size() + 1)/2 - 1]);
            cnt++;
        }
    }
    sort(rep.rbegin(), rep.rend());
    if (rep.size() == 1) {
        cout << rep[0].fi << '\n';
    } else if (rep.size() == 2) {
        int a = (rep[0].fi + 1)/2 + (rep[1].fi + 1)/2 + 1;
        int b = rep[0].fi;
        cout << max(a, b) << '\n';
    } else {
        int a = (rep[0].fi + 1)/2 + (rep[1].fi + 1)/2 + 1;
        int b = (rep[2].fi + 1)/2 + (rep[1].fi + 1)/2 + 2;
        int c = rep[0].fi;
        cout << max(max(a, b), c) << '\n';
    }
    for (int i = 1; i < rep.size(); i++) {
        cout << rep[0].se << " " << rep[i].se << '\n';
    }
}