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
    lli n, a, b, c, ans = 0;
    cin >> n >> a >> b >> c;
    if (a <= b - c) {
        ans = n / a;
    } else {
        ans = max(0LL, (n - b) / (b - c));
        n -= ans * (b - c);
        while (n >= b) {
            ans++;
            n -= b - c;
        }
        ans += n / a;
    }
    cout << ans << "\n";
}