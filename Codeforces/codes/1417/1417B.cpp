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
        int n, T;
        cin >> n >> T;
        vector< int > A, B, C, pos(n);
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            if (2 * x == T) {
                C.pb(i);
            } else if (2 * x < T) {
                A.pb(i);
            } else {
                B.pb(i);
            }
        }
        for (int i : A) {
            pos[i] = 0;
        }
        for (int i : B) {
            pos[i] = 1;
        }
        for (int i = 0; i < C.size(); i++) {
            pos[C[i]] = i % 2;
        }
        for (int x : pos) {
            cout << x << " ";
        }
        cout << '\n';
    }
}