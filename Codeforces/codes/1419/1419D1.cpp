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
    vector< int > v(n), ans(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int i = 0;
    for(i = 0; 2*i < n; i++) {
        ans[2*i] = v[i]; 
    }
    for (int j = 1; i < n; j += 2, i++) {
        ans[j] = v[i];
    }
    int A = 0;
    for (int i = 1; i < n-1; i++) {
        if (ans[i] < ans[i-1] && ans[i] < ans[i+1]) {
            A++;
        }
    }
    cout << A << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}