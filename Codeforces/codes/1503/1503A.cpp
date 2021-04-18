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
        string s;
        cin >> n >> s;
        if (s[0] != '1' || s[n-1] != '1' || count(s.begin(), s.end(), '1') % 2) {
            cout << "NO\n";
            continue;
        }
        string a = "", b = "";
        int cnt = count(s.begin(), s.end(), '1'), now = 0, zero = 0;
        for (char c : s) {
            if (c == '1') {
                char which = now < cnt/2? '(' : ')';
                a += which;
                b += which;
                now++;
            } else {
                a += "()"[zero];
                zero ^= 1;
                b += "()"[zero];
            }
        }
        cout << "YES\n";
        cout << a << "\n";
        cout << b << "\n";
    }
}