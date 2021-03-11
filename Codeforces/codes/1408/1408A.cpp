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
        int n;
        cin >> n;
        set< int > S[n];
        for (int i = 0; i < 3; i++) {
            for (int j = 0, x; j < n; j++) {
                cin >> x;
                S[j].insert(x);
            }
        }
        vector< int > ans(n);
        for (int i = 0; i < n; i++) {
            int bef = (i + n - 1) % n, aft = (i + 1) % n;
            S[i].erase(ans[bef]), S[i].erase(ans[aft]);
            ans[i] = *S[i].begin();
        }
        for (int i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}