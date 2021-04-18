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

int last[MAXC];
int fp(int x) {
    return x == last[x]? x: last[x] = fp(last[x]);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < int > v(n), to(n), ans;
        iota(last, last + n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            to[i] = (i + 1) % n;
        }

        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (__gcd(v[i], v[(i+1)%n]) == 1) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            cout << "0\n";
            continue;
        }
        
        int i = ind;
        do {
            int dest = i;
            while (__gcd(v[i], v[(i+n-1)%n]) != 1) {
                last[fp(i)] = last[fp(dest)];
                i = (i + n - 1) % n;
            }
            last[fp(i)] = fp(dest);
            i = (i + n - 1) %  n;
        } while (i != ind);

        int cur = last[0];
        while ((cur != fp(to[cur]) || __gcd(v[cur], v[to[cur]]) == 1) && cur != to[cur]) {
            ans.pb(to[cur]);
            to[cur] = to[to[cur]];
            if (__gcd(v[cur], v[to[cur]]) != 1) {
                last[fp(cur)] = fp(to[cur]);
            }
            cur = fp(to[cur]);
        }
        if (cur == to[cur] && v[cur] == 1) {
            ans.pb(cur);
        }
        cout << ans.size() << " ";
        for (int x : ans) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
}