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
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k - 3; i++, n--) {
            cout << "1 ";
        }
        if (n % 2) {
            cout << 1 << " " << n / 2 << " " << n / 2;
        } else if (n % 4) {
            cout << 2 << " " << n/2 - 1 << " " << n/2 - 1;
        } else {
            cout << n / 4 << " " << n / 4 << " " << n / 2;
        }
        cout << "\n";
    }
}