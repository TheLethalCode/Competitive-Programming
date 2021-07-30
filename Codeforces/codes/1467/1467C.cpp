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

lli smTw(lli a, lli b, lli c) {
    return min(a, b) + min(max(a, b), c);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n[3];
    for (int i = 0; i < 3; i++) {
        cin >> n[i];
    }
    vector < int > v[3];
    vector < lli > sum(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0, x; j < n[i]; j++) {
            cin >> x;
            v[i].push_back(x);
            sum[i] += x;
        }
        sort(v[i].begin(), v[i].end());
    }
    lli rem = min(*min_element(sum.begin(), sum.end()), smTw(v[0][0], v[1][0], v[2][0]));
    cout << sum[0] + sum[1] + sum[2] - 2 * rem << "\n";
}