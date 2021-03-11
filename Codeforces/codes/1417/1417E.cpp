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

lli func(vector < vector< int > > &v, int s, int &x) {
    
    if (s == -1) {
        return 0;
    }

    lli i0 = 0, i1 = 0;
    vector< vector< int > > vNew;
    for (auto &it : v) {
        vector< int > v0, v1;
        lli c0 = 0, c1 = 0;
        for (int x : it) {
            int val = x & 1 << s;
            if (!val) {
                i0 += c1;
                c0++;
                v0.pb(x);
            } else {
                i1 += c0;
                c1++;
                v1.pb(x);
            }
        }
        if (v0.size()) {
            vNew.pb(v0);
        } 
        if (v1.size()) {
            vNew.pb(v1);
        }
    }

    lli ansRest = func(vNew, s - 1, x);
    if (i0 <= i1) {
        return ansRest + i0;
    }
    x += 1 << s;
    return i1 + ansRest;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x = 0;
    cin >> n;
    vector< vector< int > > v(1);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[0].pb(x);
    }
    
    lli ans = func(v, 29, x);
    cout << ans << ' ' << x << '\n';
}