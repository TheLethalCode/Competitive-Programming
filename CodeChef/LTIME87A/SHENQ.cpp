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

lli op(lli a, lli b) {
    if (a & 1) {
        return a + b;
    } else {
        return a + b + 1;
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
        vector < lli > v(n);
        int ok = 1;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            ok &= (v[i] % 2 == v[0] % 2);
        }
        assert(ok);
        while (v.size() > 2 || v.size() == 2 && (v[0] - v[1])%2 == 0) {
            int x = v.size();
            if (v[x-1] % 2  == v[x-2] % 2) {
               lli res = op(v[x-1], v[x-2]);
               v.pop_back();
               v.pop_back();
               v.pb(res); 
            } else {
                lli res = op(v[x-2], v[x-3]), temp = v.back();
                v.pop_back();
                v.pop_back();
                v.pop_back();
                v.pb(res);
                v.pb(temp);
            }
        }
        cout << v.size() << '\n';
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}