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
    string s;
    cin >> s;
    int n = s.size();
    lli ans = 0;
    reverse(s.begin(), s.end());
    lli curPow = 1, curVal = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + curVal * (s[i] - '0')) % mod;
        lli cntNum = (s[i] - '0') * (1LL * (n - i - 1) * (n - i) / 2) % mod;
        ans = (ans +  cntNum * curPow % mod) % mod;
        curVal = (curVal + (i + 1) * curPow) % mod;
        curPow = curPow * 10 % mod;
    }
    cout << ans << "\n";
}