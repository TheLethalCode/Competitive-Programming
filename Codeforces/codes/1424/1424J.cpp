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
#define MAXC 1000005
// %

int ans[MAXC];
vector < int > prime, lp;
void linearSieve(int n){
    lp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        ans[i] = ans[i - 1];
        if (!lp[i]) {
            prime.pb(i);
            lp[i] = i;
            ans[i]++;
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
    linearSieve(MAXC);
    int t;
    cin >> t;
    while (t--) {
        int n, root;
        cin >> n;
        root = sqrt(n) + 1;
        cout << 1 + ans[n] - ans[root - 1] << "\n";
    }
}