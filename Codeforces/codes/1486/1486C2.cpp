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

int ask(int l, int r) {
    cout << "? " << min(l, r) << " " << max(l, r) << endl;
    int x;
    cin >> x;
    return x;
}

void ans(int x) {
    cout << "! " << x << endl;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int second = ask(1, n);
    int left, right, dir;
    if (second == 1 || second == n) {
        left = 1, right = n;
    } else {
        if (ask(1, second) == second) {
            left = 1;
            right = second;
        } else {
            left = second;
            right = n;
        }
    }
    dir = (left == second);

    int mid;
    while (abs(right - left) > 1) {
        mid = left + right >> 1;
        if (ask(second, mid) == second) {
            (dir? right: left) = mid;
        } else {
            dir? left = mid + 1: right = mid - 1;
        }
    }
    if (right == left) {
        ans(right);
    } else {
        ans(ask(right, left) ^ right ^ left);
    }
}