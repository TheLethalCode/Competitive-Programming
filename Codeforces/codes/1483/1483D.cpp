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
#define MAXC 605
// %

#define INF 1e15

int n, m, W[MAXC][MAXC], Q[MAXC][MAXC];
lli dis[MAXC][MAXC], save[MAXC][MAXC];
bool E[MAXC][MAXC];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(Q, 0xff, sizeof(Q));
    memset(save, 0xff, sizeof(save));
    memset(W, 0xff, sizeof(W));
    memset(E, 0, sizeof(E));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = INF;
        }
        dis[i][i] = W[i][i] = 0;
    }
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        x--, y--;
        W[x][y] = W[y][x] = dis[x][y] = dis[y][x] = z;
        E[x][y] = E[y][x] = 1;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        Q[x][y] = Q[y][x] = z;
    }

    for (int j = 0; j < n; j++) {
        for (int s = 0; s < n; s++) {
            for (int k = 0; k < n; k++) {
                save[s][j] = max(save[s][j], Q[s][k] - dis[j][k]);
            }
        }
    }
    
    int ans = 0;
    for (int s = 0; s < n; s++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (W[i][j] != -1 && E[i][j] && dis[s][i] + W[i][j] <= save[s][j]){
                    E[i][j] = E[j][i] = 0;
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}