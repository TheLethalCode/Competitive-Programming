#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 998244353
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %

inline void norm(lli &x) {
    x %= mod;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string X, Y;
    cin >> X >> Y;
    int n = X.size(), m = Y.size();
    lli A[n+1][m+1], B[n+1][m+1], ans = 0;
    memset(A, 0, sizeof(A)); // Chaotic Merge count ending with letter from X
    memset(B, 0, sizeof(B)); // Chaotic Merge count ending with letter from Y
    for (int i = 1; i <= n; i++) {
        A[i][0] = (i == 1 || X[i-1] != X[i-2])? A[i-1][0] + 1: 1;
    }
    for (int j = 1; j <= m; j++) {
        B[0][j] = (j == 1 || Y[j-1] != Y[j-2])? B[0][j-1] + 1: 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 || X[i-1] != X[i-2]) {
                A[i][j] += A[i-1][j];
            }
            if (X[i-1] != Y[j-1]) {
                A[i][j] += B[i-1][j];
                if (i > 1) {
                    A[i][j] += B[0][j];
                }
            }
            if (j == 1 || Y[j-1] != Y[j-2]) {
                B[i][j] += B[i][j-1];
            }
            if (X[i-1] != Y[j-1]) {
                B[i][j] += A[i][j-1];
                if (j > 1) {
                    B[i][j] += A[i][0];
                }
            }
            ans += A[i][j] + B[i][j];
            norm(A[i][j]);
            norm(B[i][j]);
            norm(ans);
        }
    }
    cout << ans << "\n";
}