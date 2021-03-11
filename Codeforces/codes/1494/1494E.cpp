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
    vector< set < pair< int, int > > > V(MAXC);
    set < pair< int, int > > sam, dif;
    while (m--) {
        char x;
        cin >> x;
        if (x == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;
            V[u].insert({v, c - 'a'});
            if (V[v].count({u, c - 'a'})) {
                sam.insert({min(u, v), max(u, v)});
            } else {
                auto x = V[v].lower_bound({u, -1});
                if (x != V[v].end() && x->fi == u) {
                    dif.insert({min(u, v), max(u, v)});
                }
            }
        } else if (x == '-') {
            int u, v;
            cin >> u >> v;

            auto x = V[u].lower_bound({v, -1});
            int val = x->se;
            V[u].erase(x);
            
            if (V[v].count({u, val})) {
                sam.erase({min(u, v), max(u, v)});
            } else {
                auto x = V[v].lower_bound({u, -1});
                if (x != V[v].end() && x->fi == u) {
                    dif.erase({min(u, v), max(u, v)});
                }
            }
        } else {
            int k;
            cin >> k;
            if (k % 2) {
                cout << (sam.size() || dif.size() ? "Yes\n": "No\n");
            } else {
                cout << (sam.size() ? "Yes\n": "No\n");
            }
        }
    }
}