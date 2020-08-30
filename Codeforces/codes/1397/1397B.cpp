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

const lli UP = 1LL * mod * 50;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector < lli > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    lli ans = 1LL*mod*mod;
    for (int i = 1, ok = 1; ok; i++) {
        lli pom = 1;
        vector <lli> temp;
        for (int j = 0; j < n; j++) {
            if (pom > UP) {
                ok = 0;
                break;
            }
            temp.pb(pom);
            pom *= i;
        }
        if (ok) {
            lli te = 0;
            for (int i = 0; i < n; i++) {
                te += abs(temp[i] - v[i]);
            }
            ans = min(ans, te);
        }
    }
    cout << ans << '\n';
}