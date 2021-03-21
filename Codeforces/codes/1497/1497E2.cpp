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

int n, k, dp[MAXC][21], ans[MAXC][21], cnt[50 * MAXC];
vector< int > lp, prime;
map < int, vector< int > > v;
map < int, int > temp;

void linearSieve(int n){
    lp.resize(n+1);
    for (int i = 2; i <= n; i++) {
        if (!lp[i]) {
            prime.pb(i);
            lp[i] = i;
        }
        for (auto p : prime) {
            if (p * i > n) {
                break;
            }
            lp[p * i] = p;
            if (i % p == 0) {
                break;
            }
        }
    }
}

int func(int i, int j) {
    if (ans[i][j] != -1) {
        return ans[i][j];
    } else if (i == n) {
        return ans[i][j] = 0;
    } else {
        int x = MAXC;
        for (int r = j; r >= 0; r--) {
            x = min(x, 1 + func(dp[i][r] + 1, j - r));
        }
        return ans[i][j] = x;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    linearSieve(1e7 + 5);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector< int > now(n, 1);
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            while (x != 1) {
                temp[lp[x]]++;
                x /= lp[x];
            }
            for (auto it : temp) {
                if (it.se % 2) {
                    now[i] *= it.fi;
                }
            }
            v[now[i]].pb(i);
            temp.clear();
        }
        for (int j = 0; j <= k; j++) {
            for (int x : now) {
                cnt[x] = 0;
            }
            for (int i = n - 1, en = n - 1, cp = j; i >= 0; i--) {
                while (cnt[now[i]] && !cp) {
                    cp += (cnt[now[en]] > 1);
                    cnt[now[en--]]--;
                }
                dp[i][j] = en;
                cnt[now[i]]++;
                cp -= (cnt[now[i]] > 1);
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                ans[i][j] = -1;
            }
        }
        cout << func(0, k) << "\n";
        v.clear();
    }
}