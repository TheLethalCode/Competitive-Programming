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
        int x;
        cin >> s >> x;
        int n = s.length();
        string w(n, '1');
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (i >= x && s[i] == '0') {
                w[i-x] = '0';
            }
            if (i + x < n && s[i] == '0') {
                w[i+x] = '0';
            }
        }
        for (int i = 0; i < n; i++) {
            if (i >= x && w[i-x] == '1') {
                ok &= (s[i] == '1');
            } else if (i + x < n && w[i+x] == '1') {
                ok &= (s[i] == '1');
            } else {
                ok &= (s[i] == '0');
            }
        }
        cout << (ok? w : "-1") << '\n';
    }
}