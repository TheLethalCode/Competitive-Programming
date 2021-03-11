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
    vector< int > a(3), b(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    int ans2 = 0, ans1 = mod;
    for (int i = 0; i < 3; i++) {
        ans2 += min(a[i], b[(i+1)%3]);
    }
    vector< pair< int, int > > v = {{0, 0}, {0, 2}, {1, 0}, {1, 1}, {2, 1}, {2, 2}};
    while (next_permutation(v.begin(), v.end())) {
        vector< int > teA = a, teB = b;
        for (auto pa : v) {
            int k = min(teA[pa.fi], teB[pa.se]);
            teA[pa.fi] -= k, teB[pa.se] -= k;
        }
        int temp = 0;
        for (int i = 0; i < 3; i++) {
            temp += teA[i];
        }
        ans1 = min(ans1, temp);
    }
    cout << ans1 << ' ' << ans2 << '\n';
}