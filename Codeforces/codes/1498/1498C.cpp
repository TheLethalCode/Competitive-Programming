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
#define MAXC 1005
// %

int n, k;
lli dp[MAXC][MAXC];

lli solve(int pla, int age) {
    lli &ans = dp[pla][age];
    if (ans != -1) {
        return ans;
    }
    if (pla == 0) {
        return ans = 0;
    } else if (age == 1) {
        return ans = solve(pla - 1, age);
    }
    return ans = (solve(pla - 1, age) + (1 + solve(n - pla, age - 1))) % mod;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n + 5; i++) {
            for (int j = 0; j < k + 5; j++) {
                dp[i][j] = -1;
            }
        }
        cout << 1 + solve(n, k) << "\n";
    }
}