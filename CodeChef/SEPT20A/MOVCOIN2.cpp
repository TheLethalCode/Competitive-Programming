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
#define MAXC 1003
// %

int dis[MAXC][MAXC];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector< int > to[n+1], c(n);
        for (int i = 0, a, b; i < n - 1; i++) {
            cin >> a >> b;
            to[a].pb(b);
            to[b].pb(a);
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            c[i] &= 1;
        }
        memset(dis, 0xff, sizeof(dis));
        for (int i = 1; i <= n; i++) {
            queue< int > q;
            q.push(i);
            dis[i][i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : to[u]) {
                    if (dis[i][v] == -1) {
                        dis[i][v] = dis[i][u] + 1;
                        q.push(v); 
                    }
                }
            }
        }
        lli ans = 0, p = 2;
        for (int i = 1; i <= n; i++) {
            int ok = 0;
            for (int j = 1; j <= n; j++) {
                ok ^= c[j-1] * dis[i][j];
            }
            if(!ok) {
                ans += p;
                if (ans >= mod) {
                    ans -= mod;
                }
            }
            p = p * 2;
            if (p >= mod) {
                p -= mod;
            }
        }
        cout << ans << '\n';
    }
}