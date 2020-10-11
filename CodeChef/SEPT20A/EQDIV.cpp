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
    int k;
    cin >> k;
    assert(k == 1);
    int t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        lli sum = n * (n + 1) / 2, req = sum / 2, cur = 0;
        string ans(n, '0');
        for (int i = n - 1; i >= 0; i--) {
            if (cur + i + 1 <= req) {
                cur += i + 1;
                ans[i] = '1';
            }
        }
        cout << abs(sum - 2*req) << '\n';
        cout << ans << '\n';
    }
}