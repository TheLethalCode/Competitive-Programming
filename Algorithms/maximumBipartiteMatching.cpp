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
#define sz(a) (int)(a.size())
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

class KuhnsMatch {
    int n1, n2, m;
    vector < vector< int > > edges;
    vector < int > M;
    vector < bool > vis;
public:
    KuhnsMatch(int a, int b, int c) : n1(a), n2(b), m(c) {
        edges.resize(n1);
    }
    void initGraph(vector< pair < int, int > > &E) {
        for (auto it : E) {
            edges[it.fi].emplace_back(it.se);
        }
    }
    bool dfs(int u){
        vis[u] = 1;
        for (auto v: edges[u]) {
            if (M[v] == -1) {
                M[v] = u;
                return true;
            }
        }
        for (auto v: edges[u]) {
            if (!vis[M[v]] && dfs(M[v])) {
                M[v] = u;
                return true;
            }
        }
        return false;
    }
    int maxMatch(){
        int ans = 0;
        vis.assign(n1, false);
        M.assign(n2, -1);
        for (int i = 0; i < n1; i++) {
            if (dfs(i)) {
                vis.assign(n1, 0);
                ans++;    
            }
            if (ans == min(n1, n2)) {
                return ans;
            }
        }
        return ans;
    }
};
