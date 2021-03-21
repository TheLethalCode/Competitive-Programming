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

vector < int > prime, lp;
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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    linearSieve(1e7 + 5);
    int t;
    cin >> t;
    while (t--) {
        int n, k, ans = 0;
        cin >> n >> k;
        assert(k == 0);
        map< int, int > M;
        for (int i = 0, x, wtf = 1; i < n; i++, wtf = 1) {
            cin >> x;
            map < int, int > temp;
            while (x != 1) {
                temp[lp[x]]++;
                x /= lp[x];
            }
            for (auto it : temp) {
                if (it.se % 2) {
                    wtf *= it.fi;
                }
            }
            if (M.count(wtf)) {
                ans++;
                M.clear();
            }
            M[wtf]++;
        }
        cout << ans + 1 << "\n";
    }
}