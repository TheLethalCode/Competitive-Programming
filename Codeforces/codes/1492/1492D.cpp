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
    int a, b, k;
    cin >> a >> b >> k;
    if (a == 0) {
        if (k) {
            cout << "No\n";
            return 0;
        }
        cout << "Yes\n";
        cout << string(b, '1') << "\n";
        cout << string(b, '1') << "\n";
        return 0;
    }
    if (b == 1) {
        if (k) {
            cout << "No\n";
            return 0;
        }
        cout << "Yes\n";
        cout << "1" + string(a, '0') << "\n";
        cout << "1" + string(a, '0') << "\n";
        return 0;
    }
    if (a + b - 1 <= k) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    cout << string(b, '1') + string(a, '0') << "\n";
    int zeroes = min(k, a), ones = k - zeroes;
    if (k <= a) {
        cout << string(b - 1, '1') + string(zeroes, '0') + "1" + string(a - zeroes, '0') << "\n";    
    } else {
        cout << string(b - 1 - ones, '1') + "0" + string(ones, '1') + string(a - 1, '0') + "1" << "\n";
    }
}