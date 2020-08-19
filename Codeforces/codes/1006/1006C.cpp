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
    int n;
    cin >> n;
    vector < lli > v(n), pref(n+1);
    FOR (i, n) {
        cin >> v[i];
        pref[i+1] = pref[i] + v[i]; 
    }
    lli ans = 0, sum = 0;
    set< lli > S;
    S.insert(0);
    for (int i = n-1; i >= 0; i--) {
        if (S.count(pref[i+1])) {
            ans = pref[i+1];
            break;
        }
        sum += v[i];
        S.insert(sum);
    }
    cout << ans << '\n';
}