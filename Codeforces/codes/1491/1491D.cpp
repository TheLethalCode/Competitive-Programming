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
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
            cout << "No" << '\n';
        } else {
            vector< int > b1, b2;
            while (u) {
                b1.pb(u % 2);
                u /= 2;
            }
            while (v) {
                b2.pb(v % 2);
                v /= 2;
            }
            while (b1.size() < b2.size()) b1.pb(0);
            while (b1.size() > b2.size()) b2.pb(0);

            int ok = 1;
            for (int i = 1; i < b1.size(); i++) {
                b1[i] += b1[i-1];
                b2[i] += b2[i-1];
                ok &= (b2[i] <= b1[i]);
            }
            ok &= (b2[0] <= b1[0]);
            cout << (ok? "Yes" : "No") << '\n';
        }
    }

}