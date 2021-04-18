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
    for (int i = 1; i <= t; i++) {
        int n, c;
        cin >> n >> c;
        cout << "Case #" <<i << ": ";
        if (c < n - 1 || c >= n * (n + 1) / 2) {
            cout << "IMPOSSIBLE\n"; 
            continue;
        }
        vector < int > till(n, 1), ans(n, -1), where(n);
        c -= n - 1;
        for (int i = 0; i < n - 1; i++) {
            int add = min(c, n - 1 - i);
            c -= add;
            till[i] += add;
        }
        iota(where.begin(), where.end(), 0);
        for (int i = 0; i < n; i++) {
            int pos = i + till[i];
            ans[where[pos - 1]] = i + 1;
            reverse(where.begin() + i, where.begin() + pos);
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
}