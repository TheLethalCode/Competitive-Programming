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
    int n, m;
    cin >> n >> m;
    vector < lli > pref(n+1, 0);
    FOR (i, n) {
        lli x;
        cin >> x;
        pref[i+1] = pref[i] + x;
    }
    FOR (i, m) {
        lli x;
        cin >> x;
        int pos = lower_bound(pref.begin(), pref.end(), x) - pref.begin() - 1;
        cout << pos + 1 << " " << x - pref[pos] << '\n';
    }
}