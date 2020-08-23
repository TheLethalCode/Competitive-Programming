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
        vector< pair < int, int > > V(n);
        set < pair < int, int > > S;
        FOR (i, n) {
            cin >> V[i].fi >> V[i].se;
            S.insert({V[i].fi, i});
        }
        int ans = 0;
        while (!S.empty()) {
            int cur = 0;
            auto it = S.begin();
            while ((it = S.lower_bound({cur+1, 0})) != S.end()) {
                cur = V[it->se].se;
                S.erase(it);
            }
            ans++;
        }
        cout << ans << '\n';
    }
}