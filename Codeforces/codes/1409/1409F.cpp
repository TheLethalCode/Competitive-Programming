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

int n, k;
string s, t;

int dp[205][205][205];

int recur(int i, int numA, int kLeft) {
    
    if (dp[i][numA][kLeft] != -1) {
        return dp[i][numA][kLeft];
    }
    if (i == n) {
        return dp[i][numA][kLeft] = 0;
    }
    int optA = 0, optB = 0, optC = recur(i + 1, numA, kLeft);
    if (s[i] == t[0]) {
        optA = recur(i + 1, numA + 1, kLeft);
    } else if (kLeft) {
        optA = recur(i + 1, numA + 1, kLeft - 1);
    }
    
    if (s[i] == t[1]) {
        optB = numA + recur(i + 1, numA, kLeft);
    } else if (kLeft) {
        optB = numA + recur(i + 1, numA, kLeft - 1);
    }
    return dp[i][numA][kLeft] = max(optA, max(optB, optC));
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> s >> t;
    if (t[0] == t[1]) {
        int r = count(s.begin(), s.end(), t[0]);
        r = min(n, r + k);
        cout << r * (r-1) / 2 << '\n';
    } else {
        memset(dp, 0xff, sizeof(dp));
        cout << recur(0, 0, k) << '\n';
    }
}