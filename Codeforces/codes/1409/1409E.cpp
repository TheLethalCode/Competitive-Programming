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
        int n, k;
        cin >> n >> k;
        vector< int > v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 0, x; i < n; i++) {
            cin >> x;
        }
        sort(v.begin(), v.end());
        
        vector< int > save(n);
        int end = 0;
        for (int i = 0; i < n; i++) {
            while (end < n && v[end] <= v[i] + k) {
                end++;
            }
            save[i] = end - i;
        }

        vector< int> maxSave(n + 1, 0);
        for (int i = n-1; i >= 0; i--) {
            maxSave[i] = max(maxSave[i+1], save[i]); 
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, save[i] + maxSave[i + save[i]]);
        }
        cout << ans << endl;
    }
}