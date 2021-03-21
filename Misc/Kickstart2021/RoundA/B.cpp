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

lli Lshape(int x, int y) {
    lli ans = 0;
    ans += min(x >= 2? x - 2 + 1 : 0, y >= 4? (y - 4) / 2 + 1: 0);
    ans += min(y >= 2? y - 2 + 1 : 0, x >= 4? (x - 4) / 2 + 1: 0);
    return ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, m;
        cin >> n >> m;
        vector< vector < int > > ar(n, vector< int >(m)), Hs, Vs, He, Ve;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> ar[i][j];
            }
        }
        Hs = Vs = He = Ve = ar;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                He[i][j] += ar[i][j]? He[i][j-1] : 0; 
            }
            for (int j = m - 2; j >= 0; j--) {
                Hs[i][j] += ar[i][j]? Hs[i][j+1] : 0; 
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                Ve[i][j] += ar[i][j]? Ve[i-1][j] : 0; 
            }
            for (int i = n - 2; i >= 0; i--) {
                Vs[i][j] += ar[i][j]? Vs[i+1][j] : 0; 
            }
        }
        lli ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += Lshape(Hs[i][j], Vs[i][j]);
                ans += Lshape(Hs[i][j], Ve[i][j]);
                ans += Lshape(He[i][j], Vs[i][j]);
                ans += Lshape(He[i][j], Ve[i][j]);
            }
        }
        cout << "Case #"<< z << ": " << ans << "\n";
    }
}