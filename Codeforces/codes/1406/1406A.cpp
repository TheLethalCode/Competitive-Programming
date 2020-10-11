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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[102] = {};
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            arr[x]++;
        }
        int ans = 0, cnt = 2;
        for (int i = 0; i <= 101; i++) {
            if (arr[i] == 0) {
                ans += cnt * i;
                break;
            }  else if (arr[i] == 1 && cnt == 2) {
                ans += i;
                cnt--;
            }
        }
        cout << ans << '\n';
    }
}