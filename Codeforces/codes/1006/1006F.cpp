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
    lli k, ans = 0;
    cin >> n >> m >> k;
    lli A[n][m];
    FOR (i, n) {
        FOR (j, m) {
            cin >> A[i][j];
        }
    }
    map < lli, lli > G1[n][m], G2[n][m];
    G1[0][0][A[0][0]]++;
    G2[n-1][m-1][A[n-1][m-1]]++;
    int dis = n + m - 2 >> 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j <= dis) {
                if (i) {
                    FORR (el, G1[i-1][j]) {
                        G1[i][j][el.fi xor A[i][j]] += el.se;
                    } 
                }
                if (j) {
                    FORR (el, G1[i][j-1]) {
                        G1[i][j][el.fi xor A[i][j]] += el.se;
                    }
                }
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (i + j >= dis){
                if (i < n-1) {
                    FORR (el, G2[i+1][j]) {
                        G2[i][j][el.fi xor A[i][j]] += el.se;
                    } 
                }
                if (j < m-1) {
                    FORR (el, G2[i][j+1]) {
                        G2[i][j][el.fi xor A[i][j]] += el.se;
                    }
                }
            }
            if (i + j == dis) {
                FORR (el, G2[i][j]) {
                    ans += el.se * G1[i][j][el.fi xor k xor A[i][j]];
                }
            }
        }
    }
    cout << ans << '\n';
}