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

int n, k;
bool solve(string &s) {
    vector < int > left(n+2), right(n+2);
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == '0') {
            left[i] = 0;
        } else {
            left[i] = left[i-1] + 1;
        }
    }
    for (int i = n; i; i--) {
        if (s[i-1] == '0') {
            right[i] = 0;
        } else {
            right[i] = right[i+1] + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!left[i] && left[i-1] + right[i+1] < k-1) {
            cout << i << " ";
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> n >> k >> s;
        vector < int > pos[2];
        int cur = 0;
        vector < pair< int, int > > block;
        FOR (i, n) {
            pos[s[i]-'0'].pb(i);
            if (s[i] == '1') {
                cur++;
            } else if (cur) {
                block.pb(cur, i-1);
                cur = 0;
            }
            if (i == n-1 && cur) {
                block.pb(cur, i);
            }
        }
        int cnt = 0;
        pair< int, int > mx = {0, 0};
        FORR (el, block) {
            cnt += el.fi >= k;
            mx = max(mx, el);
        }
        if (mx.fi >= 2*k || cnt > 1 || mx.fi >= k && pos[0].empty()) {
            cout << "-1\n";
            continue;
        } else if (mx.fi < k) {
            if (pos[0].size() >= 2) {
                cout << pos[0][0] + 1 << " " << pos[0][1] + 1 << '\n';
                continue;
            } else if (pos[1].size() >= 2) {
                cout << pos[1][0] + 1 << " " << pos[1][1] + 1 << '\n';
                continue;
            } else {
                cout << pos[0][0] + 1 << " " << pos[1][0] + 1 << '\n';
                continue;
            }
        }
        int c1 = mx.se - mx.fi + k, c2 = mx.se - k + 1;
        s[c1] = '0';
        if (solve(s)) {
            cout << c1 + 1 << '\n';
        } else {
            s[c1] = '1', s[c2] = '0';
            if (solve(s)) {
                cout << c2 + 1 << '\n';
            } else {
                cout << "-1\n";
            }
        }
    }
}