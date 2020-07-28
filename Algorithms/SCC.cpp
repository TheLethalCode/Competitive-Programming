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

int n, m, a, b, t, q, ok, cnt, V[MAXC];
lli k, r, x, y, z, ans;

class SCC{
    int n, m;
    vector< vector< int > > to, rto, topoSCC;
    vector< int > tout, vis, which;
    vector< set< int > > SCCto;
    SCC(int _n) : n(_n) {
        to.resize(n+1);
        rto.resize(n+1);
        tout.resize(n+1);
        vis.resize(n+1);
        which.resize(n+1);
    }
    void aE(int a, int b){
        to[a].pb(b);
        rto[b].pb(a);
    }
    void dfs(int u){
        static int t = 0;
        tout[u] = 1;
        t++;
        FORR(v, to[u]){
            if(!tout[v]){
                dfs(v);
            }
        }
        tout[u] = t++;
    }
    void dfs1(int u, vector< int > &comp){
        vis[u] = 1;
        comp.pb(u);
        FORR(v, rto[u]){
            if(!vis[v]){
                dfs1(v, comp);
            }
        }
    }
    void genComp(){
        FOR(i, n){
            if(!tout[i+1]){
                dfs(i+1);
            }
        }
        vector< int > ord(n);
        iota(ord.begin(), ord.end(), 1);
        sort(ord.begin(), ord.end(), [&](int i, int j){
            return tout[i] > tout[j];
        });
        FORR(i, ord){
            if(!vis[i]){
                vector< int > comp;
                dfs1(i, comp);
                topoSCC.pb(comp);
                m++;
            }
        }
        FOR(i, m){
            FORR(el, topoSCC[i]){
                which[el] = i;
            }
        }
    }
    void reGenGraph(){
        SCCto.resize(m);
        FOR(i, n){
            FORR(v, to[i+1]){
                if(which[i+1] != which[v]){
                    SCCto[which[i+1]].insert(which[v]);
                }
            }
        }
    }
};