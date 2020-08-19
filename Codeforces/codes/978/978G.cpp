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

struct data{
    int s, d, c, i;
    data (int _s, int _d, int _c, int _i) : s(_s), d(_d), c(_c), i(_i) {}
    bool operator< (const data& x) const {
        return d < x.d;
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector < int > ans(n+1, -1);
    vector < data > V;
    FOR (i, m) {
        int a, b ,c;
        cin >> a >> b >> c;
        V.pb(a, b, c, i+1);
        ans[b] = m + 1;
    }
    sort(V.begin(), V.end());
    FORR (ex, V) {
        int cur = ex.s;
        while (ex.c && cur < ex.d) {
            if (ans[cur] == -1) {
                ans[cur] = ex.i;
                ex.c--;
            }
            cur++;
        }
        if (ex.c) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == -1) {
            ans[i] = 0;
        }
        cout << ans[i] << " ";
    }
    cout << '\n';
}