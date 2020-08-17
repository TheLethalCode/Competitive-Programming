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

bool can(int ans, vector< lli > &P, vector< lli > &Q) {
    int n = P.size(), m = Q.size(), cur = 0;
    FOR (i, n) {
        if (P[i] < Q[cur]) {
            while (cur < m && Q[cur] <= P[i] + ans) {
                cur++;
            }
        } else {
            lli x = P[i] - Q[cur];
            if (ans < x) {
                return false;
            } else {
                lli rem = (ans <= 3*x ? ans - x >> 1: ans - 2*x);
                while (cur < m && Q[cur] <= P[i] + rem) {
                    cur++;
                }
            }
        }
        if (cur == m) break;
    }
    return cur == m;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, m, k, s;
        cin >> n >> m >> k >> s;
        vector< lli > P(n), Q(m);
        FOR (i, k) {
            cin >> P[i];
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = k; i < n; i++) {
            P[i] = (a*P[i-2] + b*P[i-1] + c) % d + 1;
        }
        FOR (i, k) {
            cin >> Q[i];
        }
        cin >> a >> b >> c >> d;
        for (int i = k; i < m; i++) {
            Q[i] = (a*Q[i-2] + b*Q[i-1] + c) % d + 1;
        }
        sort(P.begin(), P.end());
        sort(Q.begin(), Q.end());
        int ans = (1 << 30) - 1;
        for (int i = 29; i >= 0; i--) {
            if (can(ans - (1 << i), P, Q)) {
                ans -= 1 << i;
            }
        }
        cout << "Case #" << z << ": " << ans << '\n';
    }
}