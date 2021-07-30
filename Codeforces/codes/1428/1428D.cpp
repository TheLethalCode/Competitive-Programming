#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define C1 200005
#define C2 2005

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    vector < int > v(n), pos[4], done(n, 0), ans[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 0) {
            done[i] = 1;
        }
        pos[v[i]].push_back(i);
    }
    if ((pos[0].empty() && pos[1].empty()) && (v[n - 1] == 2 || v[n - 1] == 3)) {
        cout << "-1\n";
        return 0; 
    }
    int ptr = 0, last = n - 1;
    for (int x : pos[2]) {
        while (ptr < pos[1].size() && pos[1][ptr] <= x) {
            ptr++;
        }
        if (ptr == pos[1].size()) {
            cout << "-1\n";
            return 0; 
        } else {
            ans[x].push_back(last);
            ans[pos[1][ptr]].push_back(last);
            done[pos[1][ptr]] = 1;
            last--;
            ptr++;
            cnt += 2;
        }
    }
    for (int x : pos[1]) {
        if (!done[x]) {
            ans[x].push_back(last);
            last--;
            cnt++;
        }
    }
    
    ptr = n - 1;
    reverse(pos[3].begin(), pos[3].end());
    for (int x: pos[3]) {
        while (ptr > x && done[ptr]) {
            ptr--;
        }
        if (ptr == x) {
            cout << "-1\n";
            return 0; 
        } else {
            ans[x].push_back(last);
            ans[ptr].push_back(last);
            last--;
            done[ptr] = 1;
            cnt += 2;
        }
    }

    cout << cnt << "\n";
    for (int i = 0; i < n; i++) {
        for (int x : ans[i]) {
            cout << x + 1 << " " << i + 1 << "\n";
        }
    }
}