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
#define MAXC 2000005
// %
int n, m;
vector< pair < int, int > > pos[MAXC];

bool valid(int i, int j) {
    return i>=0 && j>=0 && i<n && j<m; 
}

void clear() {
    for (int i = 0; i < MAXC; i++) {
        pos[i].clear();
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int maxEle = 0;
        cin >> n >> m;
        clear();
        int ar[n][m];
        bool ok[n][m];
        lli ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> ar[i][j];
                maxEle = max(maxEle, ar[i][j]);
                pos[ar[i][j]].pb(i, j);
            }
        }
        memset(ok, 0, sizeof(ok));
        queue< pair< int, int > > q;
        for (auto ele : pos[maxEle]) {
            ok[ele.fi][ele.se] = 1;
            q.push(ele);
        }
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (ar[it.fi][it.se] != maxEle) {
                maxEle = ar[it.fi][it.se];
                for (auto ele : pos[maxEle]) {
                    if (!ok[ele.fi][ele.se]) {
                        ok[ele.fi][ele.se] = 1;
                        q.push(ele);
                    }
                }
            }
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nx = it.fi + i, ny = it.se + j;
                    if (abs(i) + abs(j) == 1 && !ok[nx][ny] && valid(nx, ny)) {
                        ans += ar[it.fi][it.se] - 1 - ar[nx][ny];
                        ar[nx][ny] = ar[it.fi][it.se] - 1;
                        ok[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        } 
        cout << "Case #"<< z << ": " << ans << "\n";
    }
}