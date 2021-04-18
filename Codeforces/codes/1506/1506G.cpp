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
        string s;
        cin >> s;
        int n = s.size();
        vector< int > pos[26];
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].pb(i);
        }
        vector < int > present;
        string ans = "";
        int last = -1;
        for (int i = 25; i >= 0; i--) {
            if (!pos[i].empty()) {
                present.pb(i);
            }
        }
        while (!present.empty()) {
            int curSize = present.size();
            for (int i = 0; i < curSize; i++) {
                bool ok = 1;
                int now = *lower_bound(pos[present[i]].begin(), pos[present[i]].end(), last);
                for (int j = i + 1; j < curSize; j++) {
                    if (pos[present[j]].back() < now) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    ans += 'a' + present[i];
                    present.erase(present.begin() + i);
                    last = now;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}