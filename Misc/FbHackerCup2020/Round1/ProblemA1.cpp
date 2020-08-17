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
        int n, k, w;
        cin >> n >> k >> w;
        vector< lli > L(n), H(n);
        FOR (i, k) {
            cin >> L[i];
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = k; i < n; i++) {
            L[i] = (a*L[i-2] + b*L[i-1] + c) % d + 1;
        }
        FOR (i, k) {
            cin >> H[i];
        }
        cin >> a >> b >> c >> d;
        for (int i = k; i < n; i++) {
            H[i] = (a*H[i-2] + b*H[i-1] + c) % d + 1;
        }
        lli ans = 1, P = 0;
        vector< lli > S(w + 5);
        FOR (i, n) {
            if (!i || L[i] > L[i-1] + w) {
                P += 2 * (H[i] + w);
                FOR (j, w+1) {
                    S[j] = H[i];
                }
            } else {
                P += 2*(L[i] - L[i-1]) + 2*max(0LL, H[i] - S[L[i] - L[i-1]]);
                for (int j = L[i]; j <= L[i] + w; j++) {
                    if (j - L[i-1] > w) {
                        S[j - L[i]] = H[i];
                    } else {
                        S[j - L[i]] = max(H[i], S[j - L[i-1]]);
                    }
                }
            }
            P %= mod;
            ans = ans * P % mod;
        }
        cout << "Case #" << z << ": " << ans << '\n';
    }
}