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
        vector < int > v(n, 1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector < int > bl;
        for (int i = 0, len = 0; i < n; i++) {
            if (v[i] && len) {
                bl.pb(len);
                len = 0;
            } else if(!v[i]) {
                len++;
            }
        }
        int win = 1;
        if (bl.empty() || bl.size() == 1 && !(bl[0] & 1)) {
            win = 0;
        } else if (bl.size()==1) {
            win = 1;
        }  else {
            int maxodd = 0, maxeven = 0;
            for (int sz : bl) {
                if (sz & 1) {
                    maxodd = max(maxodd, sz);
                } else {
                    maxeven = max(maxeven, sz);
                }
            }
            if (maxodd < maxeven) {
                win = 0;
            } else {
                sort(bl.rbegin(), bl.rend());
                win = (maxodd > 2*bl[1]);
            }
        }
        cout << (win? "Yes" : "No") << '\n';
    }
}