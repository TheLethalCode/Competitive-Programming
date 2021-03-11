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
        vector< lli > v(n), des(n+1, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        lli ans = 0;
        for (int i = 0; i < n; i++) {
            lli cha = des[i];
            if (des[i] + 1 < v[i]) {
                ans += v[i] - des[i] - 1;
                des[i] += v[i] - des[i] - 1;
            }
            des[i+1] += des[i] - v[i] + 1;
            for (int j = i + 2; j <= min(n - 1LL, v[i] + i); j++) {
                des[j]++;
            }
        }
        cout << ans << '\n';
    }
}