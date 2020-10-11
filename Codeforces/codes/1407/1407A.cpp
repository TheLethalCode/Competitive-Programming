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

int A[1005];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, cnt1 = 0, pos = -1;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            cnt1 += A[i];
        }
        if (cnt1 <= n/2) {
            cout << n / 2 << '\n';
            for (int i = 0; i < n/2; i++) {
                cout << "0 ";
            }
        } else {
            int now = n / 2 + ((n/2) & 1);
            cout << now << '\n';
            for (int i = 0; i < now; i++) {
                cout << "1 ";
            }
        }
        cout << '\n';
    }
}