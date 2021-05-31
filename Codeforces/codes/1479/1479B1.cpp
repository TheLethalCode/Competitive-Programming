#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define C1 200005
#define C2 2005

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector< int > v(n), nxt(n), pos(n + 1, n);
    for (int i = 0, x; i < n; i++) {
        cin >> v[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = pos[v[i]];
        pos[v[i]] = i;
    }

    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        if (x != -1 && v[x] == v[i]) {
            ans += v[y] != v[i];
            y = i;
        } else if (y != -1 && v[y] == v[i]) {
            ans += v[x] != v[i];
            x = i;
        } else if ((x == -1? n: nxt[x]) < (y == -1? n: nxt[y])) {
            ans += v[x] != v[i];
            x = i;
        } else {
            ans += v[y] != v[i];
            y = i;
        }
    }
    cout << ans << "\n";
}