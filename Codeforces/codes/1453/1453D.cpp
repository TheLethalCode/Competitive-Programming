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
        lli k;
        cin >> k;
        lli streak = 1LL*mod*mod;
        vector< int > ans;
        bool ok = true;
        while (k) {
            if (k < 2) {
                ok = false;
                break;
            }
            if (streak > k) {
                streak = 2;
                ans.pb(1);
            } else {
                ans.pb(0);
            }
            k -= streak;
            streak *= 2;   
        }
        if (ok) {
            cout << ans.size() << '\n';
            for (auto v : ans) {
                cout << v << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }

    }
}