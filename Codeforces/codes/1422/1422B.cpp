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

const lli INF = 1e18 + MAXC;
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int A[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }
        lli totAns = 0;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < (m + 1) / 2; j++) {
                set< pair< int, int > > S;
                lli curAns = INF;
                S.insert({i, j});
                S.insert({n - 1 - i, j});
                S.insert({i, m - 1 - j});
                S.insert({n - 1 - i, m - 1 - j});
                for (auto x : S) {
                    lli temp = 0;
                    for (auto y : S) {
                        temp += abs(A[x.fi][x.se] - A[y.fi][y.se]);
                    }
                    curAns = min(curAns, temp);
                }
                totAns += curAns;
            }
        }
        cout << totAns << "\n";
    }
}