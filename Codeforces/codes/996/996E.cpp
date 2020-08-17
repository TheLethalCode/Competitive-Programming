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
#define MAXC 1500000
// %

const lli T = 1LL * MAXC * MAXC;

lli mag(lli x, lli y) {
    return x*x + y*y;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int X[n], Y[n], ans[n];
    FOR (i, n) {
        cin >> X[i] >> Y[i];
        ans[i] = 1;
    }
    if (n >= 2) {
        vector< pair< int, int > > V(3);
        vector< int > ind[3], ch = {1, -1};
        FOR(i, 2) {
            V[i] = {X[i], Y[i]};
            ind[i].pb(i);
        }
        int whi = 2;
        for (int i = 2; i < n; i++) {
            ind[whi].pb(i);
            V[whi] = {X[i], Y[i]};
            for (int i = 0, ok = 0; i < 3 && !ok; i++) {
                for (int j = i+1; j < 3 && !ok; j++) {
                    for (int k = 0; k < 2 && !ok; k++) {
                        lli l = mag(ch[k]*V[i].fi + V[j].fi, ch[k]*V[i].se + V[j].se);
                        lli r = max(mag(V[i].fi, V[i].se), mag(V[j].fi, V[j].se));
                        if (l <= r) {
                            if (ind[i].size() > ind[j].size()) {
                                swap(i, j);
                            }
                            FORR(x, ind[i]) {
                                ind[j].pb(x);
                                ans[x] *= ch[k];
                            }
                            ind[i].clear();
                            whi = i;
                            V[j].fi += ch[k]*V[i].fi, V[j].se += ch[k]*V[i].se;
                            ok = 1;
                        }
                    }   
                }
            }
        }
        int i = 0 + (whi<=0), j = 1 + (whi<=1);
        if (mag(V[i].fi + V[j].fi, V[i].se + V[j].se) >= T) {
            FORR(x, ind[i]) {
                ans[x] *= -1;
            }
        } 
    }
    FOR (i, n) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}