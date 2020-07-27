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
vector< pair< int, pair< int, int > > > E;
vector< pair< int, int > > ed[MAXC];
int p[MAXC], ans[MAXC], n, m, a, b, c;
lli X = 0;
int f(int x){
    if(x==p[x]){
        return x;
    }
    return p[x] = f(p[x]);
}
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    FOR(i, MAXC) p[i+1]=i+1;
    cin >> n >> m;
    FOR(i, m){
        cin >> a >> b >> c;
        ed[a].pb(b, i);
        ed[b].pb(a, i);
        E.pb(c,make_pair(a, b));
    }
    vector< int > ord(E.size());
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(),[&](int i, int j){
        return E[i].fi < E[j].fi;
    });
    FORR(i, ord){
        if(f(E[i].se.fi) != f(E[i].se.se)){
            int x = f(E[i].se.fi), y = f(E[i].se.se);
            if(ed[x].size() > ed[y].size()){
                swap(x, y);
            }
            FORR(el, ed[x]){
                if(f(el.fi) == y) {
                    ans[el.se] = i;
                }
                else {
                    ed[y].pb(el.fi, el.se);
                }
            }
            p[x] = y;
            X += E[i].fi;
        }
    }
    FOR(i, m){
        cout << X - E[ans[i]].fi + E[i].fi << '\n';
    }
}