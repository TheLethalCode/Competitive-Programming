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
#define MAXC 2500005
#define UP 2300
// %


vector< int > ar1[MAXC];
vector< pair< int, int > > ar2[2*MAXC];

bool notMatch(pair< int, int > x, pair< int, int > y) {
    return x.fi != y.fi && x.fi != y.se && x.se != y.fi && x.se != y.se;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, yes = -1, ok = 0;
    cin >> n;
    vector< int > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        ar1[v[i]].pb(i);
        if (yes == -1 && ar1[v[i]].size() == 2) {
            yes = v[i];
        } else if (ar1[v[i]].size() == 2) {
            cout << "YES\n";
            cout << ar1[yes][0] + 1 << " " << ar1[v[i]][0] + 1 << " ";
            cout << ar1[yes][1] + 1 << " " << ar1[v[i]][1] + 1 << "\n";
            return 0;
        } else if (ar1[v[i]].size() == 4) {
            cout << "YES\n";
            cout << ar1[yes][0] + 1 << " " << ar1[yes][2] + 1 << " ";
            cout << ar1[yes][1] + 1 << " " << ar1[yes][3] + 1 << "\n";
            return 0;
        }
    }
    n = min(n, UP);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = v[i] + v[j];
            if (ar2[x].empty() || notMatch(ar2[x][0], {i, j})) {
                ar2[x].pb(i, j);
            }
            if (ar2[x].size() == 2) {
                cout << "YES\n";
                cout << ar2[x][0].fi + 1 << " " << ar2[x][0].se + 1 << " ";
                cout << ar2[x][1].fi + 1 << " " << ar2[x][1].se + 1 << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}