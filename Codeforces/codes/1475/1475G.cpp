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
    int t;
    cin >> t;
    while (t--) {
        int n, origN = 0;
        cin >> n;
        vector< int > v(n), cnt(C1, 0), pos(C1, -1);
        for (int &x: v) {
            cin >> x;
            cnt[x]++;
        }

        sort(v.begin(), v.end());
        origN = n;
        n = unique(v.begin(), v.end()) - v.begin();
        for (int i = 0; i < n; i++) {
            pos[v[i]] = i;
        }

        vector< int > mult[C1];
        for (int i = 1; i < C1; i++) {
            if (cnt[i]) {
                for (int j = 2 * i; j < C1; j += i) {
                    if (cnt[j]) {
                        mult[i].push_back(j);
                    }
                }
            }
        }

        vector< int > dp(n);
        for (int i = n - 1; i >= 0; i--) {
            for (int j : mult[v[i]]) {
                dp[i] = max(dp[i], dp[pos[j]]);
            }
            dp[i] += cnt[v[i]];
        }
        cout << origN - *max_element(dp.begin(), dp.end()) << "\n";
    }
}