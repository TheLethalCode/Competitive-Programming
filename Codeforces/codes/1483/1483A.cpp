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
        int n, m, ok = 1;
        cin >> n >> m;
        vector< int > available[m], ans(m, -1), cnt(n, 0);
        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            for (int j = 0, x; j < k; j++) {
                cin >> x;
                available[i].pb(x-1);
            }
        }
        vector< int > temp(m);
        iota(temp.begin(), temp.end(), 0);
        sort(temp.begin(), temp.end(), [&](int i, int j) {
            return available[i].size() < available[j].size();
        });
        for (int i : temp) {
            for (int fri : available[i]) {
                if (cnt[fri] < (m + 1) / 2) {
                    ans[i] = fri;
                    cnt[fri]++;
                    break;
                }
            }
            if (ans[i] == -1) {
                ok = 0;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int x : ans) {
                cout << x + 1 << " ";
            }
            cout << "\n";
        }
    }
}