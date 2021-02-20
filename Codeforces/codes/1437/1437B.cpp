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

int func(string s, int n, char c) {
    int ans = 0, cnt = 0;
    for (auto x : s) {
        if (x == c) {
            cnt++;
        } else if (cnt){
            ans += cnt - 1;
            cnt = 0;
        }
    }
    if (cnt) {
        ans += cnt - 1;
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << max(func(s, n, '0'), func(s, n, '1')) << '\n';
    }
}