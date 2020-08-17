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

int n;
bool val(int i, int j){
    return i<n&&j<n;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    lli G[n][n];
    G[0][0] = G[n-1][n-1] = 0;
    for (int dis = 1, p = 0; dis <= 2*n-3; dis++, p++){
        int curP = 0;
        FOR(i, n) {
            FOR (j, n) {
                if (i + j == dis) {
                    G[i][j] = curP * (1LL << p);
                    curP ^= 1;
                }
            }
        }
    }
    FOR (i, n) {
        FOR (j, n) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        lli r;
        cin >> r;
        int x = 0, y = 0;
        cout << x+1 << " " << y + 1 << endl;
        for (int i = 0; i < 2*n-2; i++) {
            if (val(x + 1, y) && (G[x+1][y] == ((1LL<<i)&r))) {
                x++;
            } else {
                y++;
            }
            cout << x + 1 << " " << y + 1 << endl; 
        }
    }
}