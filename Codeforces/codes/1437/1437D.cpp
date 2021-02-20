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

int h;
vector< int > to[MAXC];

void dfs(int u, int hi) {
    h = max(hi, h);
    for (int v : to[u]) {
        dfs(v, hi + 1);
    }
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
        vector< int > v(n);
        h = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            to[i+1].clear();
        }
        queue< int > q;
        q.push(1);
        for (int i = 1; i < n;) {
            int u = q.front();
            q.pop();
            to[u].pb(v[i]);
            q.push(v[i]);
            i++;
            for (;i < n && v[i] > v[i-1]; i++) {
                to[u].pb(v[i]);
                q.push(v[i]);
            }
        }
        dfs(1, 0);
        cout << h << '\n';
    }
}