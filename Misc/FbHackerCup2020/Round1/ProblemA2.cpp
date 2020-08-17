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
        cin >> n >> k;
        vector< lli > L(n), W(n), H(n);
        FOR (i, k) {
            cin >> L[i];
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = k; i < n; i++) {
            L[i] = (a*L[i-2] + b*L[i-1] + c) % d + 1;
        }
        FOR (i, k) {
            cin >> W[i];
        }
        cin >> a >> b >> c >> d;
        for (int i = k; i < n; i++) {
            W[i] = (a*W[i-2] + b*W[i-1] + c) % d + 1;
        }
        FOR (i, k) {
            cin >> H[i];
        }
        cin >> a >> b >> c >> d;
        for (int i = k; i < n; i++) {
            H[i] = (a*H[i-2] + b*H[i-1] + c) % d + 1;
        }
        lli ans = 1, P = 0;
        set< pair< lli, lli > > S;
        FOR (i, n) {
            auto it = S.lower_bound(make_pair(L[i], 0));
            if (it==S.end() || L[i] + W[i] < it->se) {
                P += 2 * (H[i] + W[i]);
                S.insert({L[i] + W[i], L[i]});
            } else {
                if (it->se > L[i]) {
                    P += 2 * (it->se - L[i]);
                }
                lli end = it->fi, start = min(it->se, L[i]);
                it = S.erase(it);
                while (it != S.end() && it->se <= L[i] + W[i]) {
                    P += 2 * (it->se - end - H[i]);
                    end = it->fi;
                    it = S.erase(it);
                }
                if (end < L[i] + W[i]) {
                    P += 2 * (L[i] + W[i] - end);
                    end = L[i] + W[i];
                }
                S.insert(it, {end, start});
            }
            P = (P % mod + mod) % mod;
            ans = ans * P % mod;
        } 
        cout << "Case #" << z << ": " << ans << '\n';
    }
}