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
int n;
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector< int > cnt(49);
    for(int x = 0; x <= min(n, 8); x++){
        for(int y = 0; y <= min(n-x, 48); y++){
            cnt[(9*y + 4*x) % 49] = max(cnt[(9*y + 4*x) % 49], n - x - y + 1);
        }
    }
    cout << accumulate(cnt.begin(), cnt.end(), 0LL) << '\n';
}