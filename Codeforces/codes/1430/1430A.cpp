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
    pair< pair< int, int > , int > ar[1001];
    for (int i = 0; 3*i <= 1000; i++) {
        for (int j = 0; 5*j + 3*i <= 1000; j++) {
            for (int k = 0; 7*k + 5*j + 3*i <= 1000; k++) {
                ar[7*k + 5*j + 3*i] = {{i, j}, k};
            }
        }
    }
    while (t--) {
        int n;
        cin >> n;
        if (ar[n].fi.fi || ar[n].fi.se || ar[n].se) {
            cout << ar[n].fi.fi << " " << ar[n].fi.se << " " << ar[n].se << '\n';
        } else {
            cout << "-1\n";
        }
    }
}