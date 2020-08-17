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
class DSU{
    int n;
    vector< int > par;
public:
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