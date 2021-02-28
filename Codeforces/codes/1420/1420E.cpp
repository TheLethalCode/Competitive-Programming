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
#define MAXC 85
// %

int up, A[MAXC], S[MAXC], klim;
short int dp[MAXC][MAXC*(MAXC - 1)/2][2 * MAXC];

short int func(int i, int k, int t) {
    
    int f = MAXC + t;
    if (dp[i][k][f] != -1) {
        return dp[i][k][f];
    } else if (i == up) {
        return dp[i][k][f] = t? 1e4 + 1 : 0;
    } else {
        int cha = 1e4, left = klim - k;
        for (int x = -min(S[i+1], left); x <= min(A[i] + t, left); x++) {
            int cur = A[i] + t - x;
            cha = min(cha, cur*(cur-1)/2 + func(i + 1, k + abs(x), x));
        }
        return dp[i][k][f] = cha;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, cz = 0;
    cin >> n;
    vector<int> v(n+1, 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    klim = n * (n-1) / 2;
    for (int i = 0, cnt = 0; i <= n; i++) {
        if (!v[i]) {
            cnt++, cz++;
        } else {
            A[up++] = cnt;
            cnt = 0;
        }
    }
    for (int i = up - 1; i >= 0; i--) {
        S[i] = S[i+1] + A[i];
    }
    memset(dp, 0xff, sizeof(dp));

    cz = cz * (cz - 1) / 2;
    for (int i = klim; i >= 0; i--) {
        cout << cz - func(0, i, 0) << ' ';
    }
    cout << '\n';
 
}