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
#define MAXC 300005
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
        map < int, vector< int > > M;
        vector< int > ans(n + 1, -1);
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            if (M[x].empty()) {
                M[x].pb(-1);
            }
            M[x].pb(i);
        }
        int pr = n + 1; 
        for (auto &it : M) {
            it.se.pb(n);
            int temp = 0;
            for (int i = 1; i < it.se.size(); i++) {
                temp = max(temp, it.se[i] - it.se[i-1]);
            }
            for (int i = pr - 1; i >= temp; i--) {
                ans[i] = it.fi;
            }
            pr = min(pr, temp);
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}