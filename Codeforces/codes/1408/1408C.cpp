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

#define EPS 1e-7

void solve() {
    int n, l;
    cin >> n >> l;
    vector< int > v(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    v[n+1] = l;

    vector< double > timS(n+2), timE(n+2);
    int mark = -1;
    for (int i = 1, sp = 1; i <= n + 1; i++) {
        timS[i] = timS[i-1] + 1.0 * (v[i] - v[i-1]) / sp;
        sp++;
    }
    for (int i = n, sp = 1; i >= 0; i--) {
        timE[i] = timE[i+1] + 1.0 * (v[i+1] - v[i]) / sp;
        sp++;
        if (abs(timE[i] - timS[i]) < EPS) {
            cout << timE[i] << '\n';
            return;
        } else if (timE[i] > timS[i]) {
            mark = i;
            break;
        }
    }
    
    pair< double, int > lT = {timS[mark], mark + 1}, rT = {timE[mark+1], n - mark + 1};
    int dis = v[mark + 1] - v[mark];
    if (lT > rT) {
        swap(lT, rT);
    }
    double disLeft = dis - (rT.fi - lT.fi) * lT.se;
    cout << rT.fi + disLeft/(rT.se + lT.se) << '\n';
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cout << fixed << setprecision(7);
    while (t--) {
        solve();
    }
}