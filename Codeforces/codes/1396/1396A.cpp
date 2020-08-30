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
    vector < lli > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << "1 1\n" << "0\n";
        cout << "1 1\n" << "0\n";
        cout << "1 1\n" << -v[0] << "\n";
        return 0;
    }
    vector< lli > r2(n);
    for (int i = 0; i < n; i++) {
        r2[i] = n - (v[i] % n); 
    }
    
    cout << "1 " << n - 1 << "\n";
    for (int i = 0; i < n-1; i++) {
        cout << -r2[i] * (n-1) << " ";
    }
    cout << '\n';
    
    cout << "2 " << n << "\n";
    for (int i = 1; i < n-1; i++) {
        cout << "0 ";
    }
    cout << -r2[n-1] * (n-1) << '\n';
    
    cout << "1 " << n << "\n";
    for (int i = 0; i < n; i++) {
        lli r1 = v[i] + r2[i];
        r1/= n;
        r1 -= r2[i];
        cout << -r1 * n << " "; 
    }
    cout << "\n"; 
}