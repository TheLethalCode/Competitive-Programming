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

int n;
bool val(int x) {
    return x>=0 && x <= n-2;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int u, r, d, l, ok = 0;;
        cin >> u >> r >> d >> l;
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 1; k++) {
                    for (int x = 0; x <= 1; x++) {
                        int u1 = u - i - j, r1 = r - j - k;
                        int d1 = d - k - x, l1 = l - x - i;
                        if (val(u1) && val(r1) && val(d1) && val(l1)) {
                            ok = 1;
                            goto lab;
                        }
                    }
                }
            }
        }
        lab:;
        cout << (ok ? "Yes\n" : "No\n");
    }
}