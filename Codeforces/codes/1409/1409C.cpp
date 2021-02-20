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
        int n, x, y;
        cin >> n >> x >> y;
        int curMax = 1e7;
        int a, D;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((y - x) % (j - i) == 0) {
                    int d = (y - x) / (j - i);
                    if (x - i * d >= 1 && y + (n - j - 1) * d < curMax) {
                        a = x - i * d;
                        D = d;
                        curMax = y + (n - j - 1) * d;
                    }  
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a + i * D << ' ';
        }
        cout << '\n';
    }
}