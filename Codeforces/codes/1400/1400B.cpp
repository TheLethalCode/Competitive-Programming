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
    int t;
    cin >> t;
    while (t--) {
        int p, f, cs, s, cw, w;
        cin >> p >> f;
        if (p < f) {
            swap(p, f);
        }
        cin >> cs >> cw >> s >> w;
        if (s < w) {
            swap(cs, cw);
            swap(s, w);
        }
        int ans = 0;
        if (p/w + f/w < cw) {
            cout << p/w + f/w << '\n';
            continue;
        }
        for (int i = 0; i <= cw; i++) {
            if (i > p/w) {
                break;
            }
            if (cw - i > f/w) {
                continue;
            }
            int cp = p - i * w, cf = f - (cw - i) * w, Cs = cs, temp = cw, am;
            am = min(Cs, cp/s), temp += am, Cs -= am;
            am = min(Cs, cf/s), temp += am;
            ans = max(ans, temp);
        }
        cout << ans << '\n';
    }
}