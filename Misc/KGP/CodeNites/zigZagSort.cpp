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
        cin >> n;
        vector < int > v(2*n);
        FOR (i, 2*n) {
            cin >> v[i];
        }
        vector < int > temp = v;
        sort(temp.begin(), temp.end());
        int less = temp[n-1];
        vector < int > ind[2][2];
        for (int i = 0; i < 2*n; i++) {
            ind[v[i] > less][i&1].pb(i);
        }
        vector < pair< int, int > > A;
        if (ind[0][1].size() < ind[0][0].size()) {
            for (int i = 0; i < ind[0][1].size(); i++) {
                A.pb(ind[0][1][i], ind[1][0][i]);
            }
        } else {
            for (int i = 0; i < ind[0][0].size(); i++) {
                A.pb(ind[0][0][i], ind[1][1][i]);
            }
        }
        cout << A.size() << '\n';
        FORR (p, A) {
            cout << p.fi + 1 << " " << p.se + 1 << '\n';
        }
    }
}