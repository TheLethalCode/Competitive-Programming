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

vector< int > to[MAXC], rto[MAXC];
lli totSum[MAXC], P[MAXC], A[MAXC], B[MAXC], up[MAXC][20];

class DSU{
    int n;
    vector< int > par;
public :
    DSU(int _n) : n(_n) {
        par.resize(n+1);
        iota(par.begin(), par.end(), 0);
    }
    int fp(int x){
        return x==par[x]?x:par[x]=fp(par[x]);
    }
    bool unite(int x, int y){
        x = fp(x);
        y = fp(y);
        if(x == y){
            return false;
        }
        par[y] = x;
        return true;
    }
};

void dfs(int u, int p = 0) {
    up[u][0] = p;
    for (int i = 1; i <= 19; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    totSum[u] += A[u-1];
    FORR (v, rto[u]) {
        if (v != p) {
            totSum[v] += totSum[u];
            dfs(v, u);
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FOR (i, n+1) {
            to[i].clear();
            rto[i].clear();
            totSum[i] = 0;
        }
        FOR (i, n-1) {
            int x, y;
            cin >> x >> y;
            to[x].pb(y);
            to[y].pb(x);
        }
        int H[n+1];
        FOR (i, n) {
            cin >> P[i];
            H[P[i]] = i + 1;
        } 
        FOR (i, n) {
            cin >> A[i];
        }
        FOR (i, n) {
            cin >> B[i];
        }
        DSU comp(n);
        reverse(P, P + n);
        vector < int > done(n+1);
        FOR (i, n) {
            FORR (v, to[P[i]]) {
                if (done[v]) {
                    int x = comp.fp(v);
                    rto[P[i]].pb(x);
                    rto[x].pb(P[i]);
                    comp.unite(P[i], x);
                }
            }
            done[P[i]] = 1;
        }
        int root = P[n-1];
        dfs(root);
        FOR (i, n) {
            if (totSum[i+1] < B[i]) {
                cout << -1 << ' ';
                continue;
            }
            int x = i + 1;
            for (int j = 19; j >= 0; j--) {
                if (totSum[up[x][j]] >= B[i]) {
                    x = up[x][j];
                }
            }
            cout << H[x] << ' ';
        }
        cout << '\n';
    }   
}