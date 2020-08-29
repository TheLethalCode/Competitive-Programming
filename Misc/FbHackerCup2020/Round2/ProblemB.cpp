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

lli nc2(lli n) {
    return n * (n-1) / 2;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cout << fixed << setprecision(8);
    for (int z = 1; z <= t; z++) {
        int n;
        long double p;
        cin >> n >> p;
        long double E[n+1][n+1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                E[i][j] = 0;
            }
        }
        E[1][2] = E[2][2] = 1;
        for (int j = 3; j <= n; j++) {
            for (int i = 1; i <= j; i++) {
                E[i][j] += nc2(i-1) * E[i-1][j-1] + nc2(j-i) * E[i][j-1];
                E[i][j] += (i-1)*(j-i)*(p*E[i-1][j-1] + (1-p)*E[i][j-1]);
                E[i][j] += (i-1)*p*E[i-1][j-1] + (j-i)*(1-p)*E[i][j-1];
                E[i][j] /= nc2(j);
                E[i][j] += 1;
            }
        }
        cout << "Case #" << z << ": \n";
        for (int i = 1; i <= n; i++) {
            cout << E[i][n] << '\n';
        }
    }
}