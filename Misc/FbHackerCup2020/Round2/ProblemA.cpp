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
    for (int z = 1; z <= t; z++) {
        int n, k;
        cin >> n >> k;
        vector < lli > S(n), X(n), Y(n);
        for (int i = 0; i < k; i++) {
            cin >> S[i];
        }
        lli a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = k; i < n; i++) {
            S[i] = (S[i-2] * a + S[i-1] * b + c) % d;
        }
        for (int i = 0; i < k; i++) {
            cin >> X[i];
        }
        cin >> a >> b >> c >> d;
        for (int i = k; i < n; i++) {
            X[i] = (X[i-2] * a + X[i-1] * b + c) % d;
        }
        for (int i = 0; i < k; i++) {
            cin >> Y[i];
        }
        cin >> a >> b >> c >> d;
        for (int i = k; i < n; i++) {
            Y[i] = (Y[i-2] * a + Y[i-1] * b + c) % d;
        }
        lli lo = 0, hi = 0, tot = 0, excess = 0, def = 0;
        for (int i = 0; i < n; i++) {
            lo += X[i];
            hi += X[i] + Y[i];
            tot += S[i];
            excess += max(0LL, S[i] - X[i] - Y[i]);
            def += max(0LL, X[i] - S[i]);
        }
        if (tot < lo || hi < tot) {
            cout << "Case #" << z << ": -1\n";
            continue;
        }
        cout << "Case #" << z << ": " << max(excess, def) << '\n';
    }
}