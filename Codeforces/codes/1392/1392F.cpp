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
    lli S = 0;
    for (lli i = 0, x; i < n; i++) {
        cin >> x;
        S += x;
    }
    S -= 1LL * n * (n+1) / 2 ;
    vector < lli > V(n);
    iota(V.begin(), V.end(), 1);
    for_each(V.begin(), V.end(), [&](lli& x){
        x += S / n;
    });
    S %= n;
    for_each(V.begin(), V.begin() + S, [&](lli& x){
        x += 1;
    });
    FOR (i, n) {
        cout << V[i] << ' ';
    }
    cout << '\n';
}