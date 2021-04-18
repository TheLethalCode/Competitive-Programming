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
        int n;
        cin >> n;
        vector< int > q(n), sma(n), big(n);
        set < int > S1, S2;
        for (int i = 0; i < n; i++) {
            cin >> q[i];
            S1.insert(i + 1);
        }
        S2 = S1;
        sma[0] = big[0] = q[0];
        S1.erase(q[0]);
        S2.erase(q[0]);
        for (int i = 1; i < n; i++) {
            if (q[i] == q[i-1]) {
                sma[i] = *S1.begin();
                S1.erase(S1.begin());
                auto it = prev(S2.lower_bound(q[i]));
                big[i] = *it;
                S2.erase(it);
            } else {
                sma[i] = big[i] = q[i];
                S1.erase(q[i]);
                S2.erase(q[i]);
            }
        }
        for (auto x : sma) {
            cout << x << " ";
        }
        cout << "\n";
        for (auto y : big) {
            cout << y << " ";
        }
        cout << "\n";
    }
}