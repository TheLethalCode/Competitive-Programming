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
        lli n, ans = 0, sum = 0, x;
        cin >> n;
        cout << 1 << " " << (1 << 20) << endl;
        cin >> sum; 
        sum -= (n<<20);
        ans += sum & 1;
        for (int i = 1, cnt; i < 20; i++) {
            cout << 1 << " " << (1<<i) << endl;
            cin >> x;
            assert(x != -1);
            cnt = (sum + (n << i) - x) >> (i+1);
            ans += (cnt & 1) << i;
        }
        cout << 2 << " " << ans << endl;
        cin >> x;
        assert(x != -1);
    }
}