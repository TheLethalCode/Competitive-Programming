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

int par[MAXC];

int fp(int x) {
    return x == par[x]? x : fp(par[x]);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + MAXC, 0);

    int n, root = -1, ans = 0;
    cin >> n;
    vector< int > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == i + 1 && root == -1) {
            root = v[i];
        } else if (v[i] == i + 1) {
            v[i] = root;
            ans++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i+1 != v[i] && fp(i+1) == fp(v[i])) {
            if (root == -1) {
                root = i + 1;
            } 
            v[i] = root;
            ans++;
        } else {
            par[fp(i+1)] = par[fp(v[i])];
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}