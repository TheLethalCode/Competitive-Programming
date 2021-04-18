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
#define INF 1LL*mod*mod
// %

void djikstra(vector< pair < int , lli> > E[], int n, int s, lli *dis) {

    fill_n(dis, n, INF);
    dis[s] = 0;
    set < pair< lli, int > > S;
    S.insert({0, s});
    
    while (!S.empty()) {
        int u = S.begin()->second;
        S.erase(S.begin());
        for (auto v : E[u]) {
            if (dis[v.first] > dis[u] + v.second) {
                if (dis[v.first] != INF) {
                    S.erase({dis[v.first], v.first});
                }
                dis[v.first] = dis[u] + v.second;
                S.insert({dis[v.first], v.first});
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair< int , int > start, dest, insta[m];
    cin >> start.fi >> start.se >> dest.fi >> dest.se;
    for (int i = 0; i < m; i++) {
        cin >> insta[i].fi >> insta[i].se;
    }
    int colOrder[m], rowOrder[m];
    iota(rowOrder, rowOrder + m, 0);
    sort(rowOrder, rowOrder + m, [&](int i, int j){
        return insta[i].fi < insta[j].fi;
    });
    iota(colOrder, colOrder + m, 0);
    sort(colOrder, colOrder + m, [&](int i, int j){
        return insta[i].se < insta[j].se;
    });
    vector< pair< int, lli > > E[m + 1];
    for (int i = 0; i < m - 1; i++) {
        int curR = rowOrder[i], curC = colOrder[i];
        int rR = rowOrder[i + 1], rC = colOrder[i + 1];
        E[curR].pb(rR, insta[rR].fi - insta[curR].fi);
        E[rR].pb(curR, insta[rR].fi - insta[curR].fi);
        E[curC].pb(rC, insta[rC].se - insta[curC].se);
        E[rC].pb(curC, insta[rC].se - insta[curC].se);
    }
    for (int i = 0; i < m; i++) {
        E[m].pb(i, min(abs(insta[i].fi - start.fi), abs(insta[i].se - start.se)));
    }
    lli dis[m + 1], ans = abs(start.fi - dest.fi) + abs(start.se - dest.se);
    djikstra(E, m + 1, m, dis);
    for (int i = 0; i < m; i++) {
        ans = min(ans, dis[i] + abs(insta[i].fi - dest.fi) + abs(insta[i].se - dest.se));
    }
    cout << ans << "\n";
}