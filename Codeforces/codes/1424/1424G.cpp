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
    map< int, int > M;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        M[x]++;
        M[y]--;
    }
    int ans = 0, cur = 0, when = 0;
    for (auto it : M) {
        cur += it.se;
        if (ans < cur) {
            ans = cur;
            when = it.fi;
        }
    }
    cout << when << " " << ans << "\n";
}