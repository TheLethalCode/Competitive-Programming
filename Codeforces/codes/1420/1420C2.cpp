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

lli change(vector<int> &v, int i, int j) {
    lli ans = 0;
    for (int r = i; r <= j; r++) {
        if (v[r] > v[r-1] && v[r] > v[r+1]) {
            ans += v[r];
        } else if (v[r] < v[r-1] && v[r] < v[r+1]) {
            ans -= v[r];
        }
    }
    return ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector< int > v(n+2, -1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        lli cur = change(v, 1, n);
        cout << cur << '\n';
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (r - l > 5) {
                cur -= change(v, l-1, l+1) + change(v, r-1, r+1);
                swap(v[l], v[r]);
                cur += change(v, l-1, l+1) + change(v, r-1, r+1);
            } else {
                cur -= change(v, l-1, r+1);
                swap(v[l], v[r]);
                cur += change(v, l-1, r+1);
            }
            cout << cur << '\n';
        }
    }
}