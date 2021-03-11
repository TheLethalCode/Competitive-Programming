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

int solve(vector< int > &a, vector< int > &b) {
    int n = a.size(), m = b.size(), up = 0;
    b.pb(2e9);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector< int > alr;
    for (int i = 0; i < n; i++) {
        while (up < m && b[up] < a[i]) {
            up++;
        }
        if (a[i] == b[up]) {
            alr.pb(a[i]);
        }
    }

    int ans = alr.size();
    for (int i = 0; i < m; i++) {
        int box = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        int bE = b[i], bS = bE - box + 1;
        int spe = i - (lower_bound(b.begin(), b.end(), bS) - b.begin() - 1);
        int left = alr.end() - upper_bound(alr.begin(), alr.end(), b[i]);
        ans = max(ans, spe + left);
    }
    return ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< int > aN, aP, bN, bP;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            if (x < 0) {
                aN.pb(-x);
            } else {
                aP.pb(x);
            }
        }
        for (int i = 0, x; i < m; i++) {
            cin >> x;
            if (x < 0) {
                bN.pb(-x);
            } else {
                bP.pb(x);
            }
        }
        cout << solve(aN, bN) + solve(aP, bP) << '\n';
    }
}