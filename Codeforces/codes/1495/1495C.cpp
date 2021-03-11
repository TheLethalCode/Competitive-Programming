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
        int n, m;
        cin >> n >> m;
        vector < string > v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        for (int i = 0; i < n; i += 3) {
            v[i] = string(m, 'X');
            if (i + 2 < n) {
                int mark = -1;
                for (int j = i + 1; j <= i + 2 && mark == -1; j++) {
                    for (int k = 0; k < m && mark == -1; k++) {
                        if (v[j][k] == 'X') {
                            mark = k;
                        }
                    }
                }
                mark = max(mark, 0);
                v[i + 1][mark] = v[i + 2][mark] = 'X';
            }
        }

        if (n % 3 == 0) {
            for (int i = 0; i < m; i++) {
                if (v[n-1][i] == 'X') {
                    v[n-2][i] = 'X';
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << v[i] << '\n';
        }
    }
}