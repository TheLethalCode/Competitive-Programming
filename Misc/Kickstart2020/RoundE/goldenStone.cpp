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
#define FORR(x,v) for(auto &x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, m, s, r;
        cin >> n >> m >> s >> r;
        vector < int > to[n+1];
        vector < pair < int, vector< int > > > combine[s+1];
        vector < vector < lli > > disS(n+1, vector< lli >(s+1, 1e12));
        set < pair < lli, pair < int, int > > > S;
        FOR (i, m) {
            int a, b;
            cin >> a >> b;
            to[a].pb(b), to[b].pb(a);
        }
        FOR (i, n) {
            int x, y;
            cin >> x;
            FOR (j, x) {
                cin >> y;
                disS[i+1][y] = 0;
                S.insert({0, {i+1, y}});
            }
        }
        FOR (i, r) {
            pair < int, vector< int > > Q;
            int x, y;
            cin >> x;
            FOR (j, x) {
                cin >> y;
                Q.se.pb(y);
            }
            cin >> Q.fi;
            FORR (j, Q.se) {
                combine[j].pb(Q);
            }
        }
        while (!S.empty()) {
            auto u = *S.begin();
            S.erase(S.begin());
            FORR (v, to[u.se.fi]) {
                if (disS[v][u.se.se] > u.fi + 1) {
                    disS[v][u.se.se] = u.fi + 1;
                    S.insert({u.fi + 1, {v, u.se.se}});
                }
            }
            FORR (R, combine[u.se.se]) {
                lli temp = 0;
                FORR (ing, R.se) {
                    temp += disS[u.se.fi][ing];
                }
                if (disS[u.se.fi][R.fi] > temp) {
                    disS[u.se.fi][R.fi] = temp;
                    S.insert({temp, {u.se.fi, R.fi}});
                }
            }
        }
        lli ans = 1e12;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, disS[i][1]);
        }
        cout << "Case #" << z << ": " << (ans == 1e12?-1:ans) << '\n';
    }
}