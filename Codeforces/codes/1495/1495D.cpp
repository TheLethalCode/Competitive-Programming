#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 998244353
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 405
// %

int n, m, dis[MAXC][MAXC], ans[MAXC][MAXC], src[MAXC], D[MAXC], cnt[MAXC];
vector< int > E[MAXC];

void bfs(int s) {
    dis[s][s] = 0;
    queue< int > q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : E[u]) {
            if (dis[s][v] == -1) {
                dis[s][v] =  dis[s][u] + 1;
                q.push(v);
            }
        }
    }
}

lli calcNum(int s, int t) {
    queue< int > q;
    memset(D, 0xff, sizeof(D));
    for (int i = 0; i < n; i++) {
        if (dis[s][i] + dis[i][t] == dis[s][t]) {
            q.push(i);
            src[i] = i;
            D[i] = 0;
            cnt[i] = 1;
        }
    }
    
    if (q.size() > dis[s][t] + 1) {
        return 0;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : E[u]) {
            if (D[v] == -1) {
                D[v] = D[u] + 1;
                src[v] = src[u];
                cnt[v] = 0;
                q.push(v);
            }
            if (abs(dis[s][src[u]] - dis[s][src[v]]) > abs(D[v] - D[u] - 1)) {
                return 0;
            }
            cnt[v] += (D[v] == D[u] + 1);
        }
    }

    lli ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * cnt[i] % mod;
    }
    return ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dis, 0xff, sizeof(dis));
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        E[a].pb(b);
        E[b].pb(a);
    }
    for (int i = 0; i < n; i++) {
        bfs(i);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ans[i][j] = ans[j][i] = calcNum(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}