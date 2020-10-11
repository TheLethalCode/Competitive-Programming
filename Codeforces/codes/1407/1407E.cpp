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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector< int > to[n+1][2];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a != b){
            to[b][c].pb(a);
        }
    }
    int dis[n+1], ans[n+1];
    memset(ans, 0xff, sizeof(ans));
    memset(dis, 0xff, sizeof(dis));
    dis[n] = ans[n] = 0;
    queue< int > q;
    q.push(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int _ = 0; _ < 2; _++) {
            for (int v : to[u][_]) {
                if (ans[v] == -1) {
                    ans[v] = !_;
                } else if (ans[v] == _ && dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                } 
            }
        }
    }
    cout << dis[1] << '\n';
    for (int i = 1; i <= n; i++) {
        cout << max(0, ans[i]); 
    }
    cout << '\n';
}