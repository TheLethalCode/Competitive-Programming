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
    int n, q, co = 0;
    cin >> n >> q;
    vector< int > v(n);
    for (int i = 0;i < n; i++) {
        cin >> v[i];
        co += v[i];
    }

    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            v[x-1] = 1 - v[x-1];
            if (v[x-1]) {
                co++;
            } else {
                co--;
            }
        } else {
            cout << (co >= x? 1 : 0) << '\n';
        }
    }
}