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
#define MAXC 5005
// %
int solve(int l, int r, vector< int > v) {
    if (l == r) {
        return 0;
    }
    if (l + 1 == r) {
        return v[l] != 0;
    }
    vector < int > ind = {l-1};
    int sm = *min_element(v.begin() + l, v.begin() + r);
    for (int i = l; i < r; i++) {
        if (sm == v[i]) {
            ind.pb(i);
        }
        v[i] -= sm;
    }
    ind.pb(r);
    int temp = 0, n = r - l - (sm ? 0: (int)ind.size()- 2);
    for (int i = 1; i < ind.size(); i++) {
        temp += solve(ind[i-1] + 1, ind[i], v);
    }
    return min(n, sm + temp);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector < int > v(n);
    FOR (i, n) {
        cin >> v[i];
    }
    cout << solve(0, n, v) << '\n';
}