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

const lli UP = 2LL * mod * mod;  

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector < lli > V(n+1), next(n+1);
    FOR (i, n) {
        cin >> V[i+1];
    }
    for (int i = n, pr = n + 1; i >= 0; i--) {
        next[i] = pr;
        if (V[i] > 1) {
            pr = i;
        }
    }
    lli ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = i;
        lli sum = 0, pro = 1;
        while(cur <= n && UP / V[cur] > pro) {
            sum += V[cur], pro *= V[cur];
            int poss = next[cur] - cur - 1;
            if (pro % k == 0 && sum <= pro/k && pro/k <= sum + poss){
                ans++;
            }
            sum += poss;
            cur = next[cur];
        }
    }
    cout << ans << '\n';
}