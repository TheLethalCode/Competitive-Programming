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
        int n, k, ma = 0;
        cin >> n >> k;
        set < int > S1, S2;
        for (int i = 0; i < n; i++) {
            S1.insert(i);
        }
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            ma = max(ma, x);
            S1.erase(x);
            S2.insert(x);
        }
        int mex = S1.empty() ? n: *S1.begin();
        if (mex > ma) {
            cout << n + k << "\n";
        } else {
            cout << n + (!S2.count((ma + mex + 1) / 2) && k) << "\n";
        }
    }
}