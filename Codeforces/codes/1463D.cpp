#include <bits/stdc++.h>
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

int n, v[C1];

bool compFunc(int ind, bool dir) {
    int rest = dir? n - ind - 1: ind;
    for (int i = 0; i <= (dir? ind: n - ind - 1) ; i++) {
        if ((dir? 2*n - v[ind - i]: v[ind + i] - 1) - rest - 2 * i <= 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v, v + n);
        // cout << compFunc(0, false) << endl;
        int lo = 0, hi = n - 1, numMins = 0, numMaxs = 0;
        while (hi >= lo) {
            int mid = lo + hi >> 1;
            if (compFunc(mid, true)) {
                numMins = mid + 1;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        lo = 0, hi = n - 1;
        while (hi >= lo) {
            int mid = lo + hi >> 1;
            if (compFunc(mid, false)) {
                numMaxs = n - mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // cout << numMins << " " << numMaxs << endl;
        int ans = numMins + numMaxs - n + 1;
        cout << max(ans, 0) << "\n";
    }
}