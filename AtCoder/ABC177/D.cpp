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

class DSU{
    int n;
    vector< int > par, siz;
public:
    DSU(int _n) : n(_n) {
        par.resize(n+1);
        siz.resize(n+1, 1);
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
        siz[x] += siz[y];
        return true;
    }
    int si(int a) {
        return siz[fp(a)];
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU A(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        A.unite(a, b);
    }
    int x = 0;
    for (int i = 1; i <= n; i++) {
        x = max(x, A.si(i));
    }
    cout << x << '\n';
}