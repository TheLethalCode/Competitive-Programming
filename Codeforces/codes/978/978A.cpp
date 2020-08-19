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
    int n;
    cin >> n;
    vector < int > v(n), cnt(1001, -1);
    FOR (i, n) {
        cin >> v[i];
        cnt[v[i]] = i+1;
    }
    vector < pair< int, int > > V;
    FOR (i, 1001) {
        if (cnt[i] != -1) {
            V.pb(cnt[i], i);
        }
    }
    sort(V.begin(), V.end());
    cout << V.size() << '\n';
    FORR (c, V) {
        cout << c.se << ' ';
    }
    cout << '\n';
}