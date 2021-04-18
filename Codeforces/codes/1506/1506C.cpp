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

string a, b;
int n, m;
void solve() {
    for (int i = n; i >= 1; i--) {
        for (int stA = 0; stA <= n - i; stA++) {
            for (int stB = 0; stB <= m - i; stB++) {
                if (a.substr(stA, i) == b.substr(stB, i)) {
                    cout << n + m - 2*i << "\n";
                    return;
                }
            }
        }
    }
    cout << n + m << "\n";
    return;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a.size() > b.size()) {
            swap(a, b);
        }
        n = a.size();
        m = b.size();
        solve();
    }
}