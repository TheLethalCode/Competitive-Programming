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
        int n = s.length();
        int ok = 1, oneAdj = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1] && s[i] == '1') {
                oneAdj = 1;
            } else if (s[i] == s[i-1] && oneAdj) {
                ok = 0;
                break;
            }
        }
        cout << (ok? "YES\n" : "NO\n");
    }
}