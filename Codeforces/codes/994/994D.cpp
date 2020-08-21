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
    vector< pair< int, int > > X(n), Y(m);
    FOR (i, n) {
        cin >> X[i].fi >> X[i].se;
    }
    FOR (i, m) {
        cin >> Y[i].fi >> Y[i].se;
    }
    vector<int> cX(n), cY(m);
    int val = -1;
    int ok = 1, nok = 0;
    FOR (i, n) {
        int ma = 0, pval = -1;
        FOR (j, m) { 
            if (((X[i].fi == Y[j].fi) xor (X[i].se == Y[j].se)) || ((X[i].fi == Y[j].se) xor (X[i].se == Y[j].fi))){
                ma++;
                int cur;
                if (X[i].fi == Y[j].fi || X[i].fi == Y[j].se) {
                    cur = X[i].fi;
                } else {
                    cur = X[i].se;
                }
                if (ma >= 2 && pval != cur) {
                    cout << "-1\n";
                    return 0;
                }
                pval = cur;
            }
        }
        if (ma && val != -1 && pval != val) {
            ok = 0;
        } else if (pval != -1){
            val = pval;
        }
    }
    if (ok) {
        cout << val << "\n";
        return 0;
    }
    FOR (j, m) {
        int ma = 0, pval = -1;
        FOR (i, n) {
            if (((X[i].fi == Y[j].fi) xor (X[i].se == Y[j].se)) || ((X[i].fi == Y[j].se) xor (X[i].se == Y[j].fi))){
                ma++;
                int cur;
                if (X[i].fi == Y[j].fi || X[i].fi == Y[j].se) {
                    cur = X[i].fi;
                } else {
                    cur = X[i].se;
                }
                if (ma >= 2 && pval != cur) {
                    cout << "-1\n";
                    return 0;
                }
                pval = cur;
            }
        }
    }
    cout << "0\n";
    return 0;
}